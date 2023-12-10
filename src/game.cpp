#include "utils/game.h"

void GameLoad(Game *&game, char **argv) {
	linked_list_player *players = NULL;

	ReadPlayers(&players, argv);

	game->game_done = false;
	game->round_done = false;
	game->players = players;
	game->dictionary = ReadDictionary("ods4.txt");
	game->current_word = strdup(""); //size = strlen("") + 1
	game->char_count = strlen(game->current_word);

	std::cout << GetListSize(game->dictionary) << std::endl;
	GameLoop(game);
}

bool PrintSinge(Game *game, bool do_print) {
	if (game == NULL) return false;
	bool game_done = false;
	for (auto cursor = game->players; cursor != NULL; cursor = cursor->next) {
		if (cursor->player->quart_singe >= 4) {
			game_done = true;
			break;
		}
		if (do_print) {
			std::cout << cursor->player->number + 1 << GetPlayerType(cursor->player) << " : " << (float)cursor->player->quart_singe / 4 << (cursor->next == NULL ? "\n" : "; ");
		}
	}
	return game_done;
}


void FreeMemory(Game *game) {
	if (game == NULL) return;

	for (auto cursor = &game->dictionary; *cursor != NULL; ) {
		auto tmp = *cursor;
		*cursor = (*cursor)->next;
		delete tmp;
	}

	for (auto cursor = &game->players; *cursor != NULL; ) {
		auto tmp = *cursor;
		*cursor = (*cursor)->next;
		delete tmp;
	}

	delete game->current_word;
	delete game;
}


bool WordGuess(Game *&game, linked_list_player *&cursor) {
	char str[256];
	linked_list_player *before_player = FindPlayerBefore(game->players, cursor->player->number);
	auto player = before_player->player;

	if (player->type == PlayerType::Bot)
	{
		strcpy(str, BotGuessWord(game->dictionary, game->current_word));
		std::cout << player->number + 1 << GetPlayerType(player)
			<< ", saisir le mot > " << str << std::endl;
	}
	else
	{
		std::cout << player->number + 1 << GetPlayerType(player)
			<< ", saisir le mot > ";
		std::cin >> str;
	}

	std::transform(str, str + strlen(str), str, toupper);

	if (ListContains(game->dictionary, str)) {
		if (isWordCoherent(game->current_word, str)) {
			std::cout << "Le mot " << str << " existe, le joueur " << cursor->player->number + 1 << GetPlayerType(cursor->player)
				<< " prend un quart de singe." << std::endl;
			cursor->player->quart_singe++;
			game->round_done = true;
			return true;
		}
		else {
			std::cout << "Le mot " << str << " ne commence pas par les lettres attendues, le joueur " << player->number + 1 << GetPlayerType(player)
				<< " prend un quart de singe." << std::endl;
			player->quart_singe++;
			cursor = FindPlayerBefore(game->players, player->number);
			game->current_word = strdup("");
			game->char_count = strlen(game->current_word);
			return false;
		}
	}
	else {
		std::cout << "Le mot " << str << " n'existe pas, le joueur " << player->number + 1 << GetPlayerType(player)
			<< " prend un quart de singe." << std::endl;
		player->quart_singe++;
		cursor = FindPlayerBefore(game->players, player->number);
		game->current_word = strdup("");
		game->char_count = strlen(game->current_word);
		return false;
	}
}


bool NewLetter(Game *&game, linked_list_player *&cursor, char c) {
	char *tmp = (char *)realloc(game->current_word, game->char_count + 2);
	game->current_word = tmp;
	game->current_word[game->char_count++] = c;
	game->current_word[game->char_count] = '\0';

	if (ListContains(game->dictionary, game->current_word)) {
		std::cout << "Le mot " << game->current_word << " existe, le joueur " << cursor->player->number + 1 << GetPlayerType(cursor->player)
			<< " prend un quart de singe." << std::endl;
		cursor->player->quart_singe++;
		return true;
	}
	return false;
}


void GameLoop(Game *game) {
	while (!game->game_done) {
		while (!game->round_done) {
			for (auto cursor = game->players; cursor != NULL; cursor = cursor->next) {
				char c;
				std::cout << cursor->player->number + 1 << GetPlayerType(cursor->player) << ", (" << game->current_word << ") > ";
				if (cursor->player->type == PlayerType::Bot) {
					c = BotChoose(game->dictionary, game->current_word);
					std::cout << c << std::endl;
				}
				else
					std::cin >> c;
				if (c == '!') {
					std::cout << "Le joueur " << cursor->player->number + 1 << " abandonne la manche et prend un quart de singe." << std::endl;
					cursor->player->quart_singe++;
					game->round_done = true;
					break;
				}
				else if (c == '?') {
					if (WordGuess(game, cursor)) {
						game->round_done = true;
						break;
					}
				}
				else {
					if (NewLetter(game, cursor, toupper(c))) {
						if (PrintSinge(game, false)) {
							game->round_done = true;
							game->game_done = true;
							break;
						}

						PrintSinge(game, true);
						cursor = FindPlayerBefore(game->players, cursor->player->number);
						game->current_word = strdup("");
						game->char_count = strlen(game->current_word);
					}
				}
			}
		}
		if (PrintSinge(game, true))
			game->game_done = true;
		game->round_done = false;
		game->current_word = strdup("");
		game->char_count = strlen(game->current_word);
	}
	std::cout << "La partie est finie." << std::endl;
}
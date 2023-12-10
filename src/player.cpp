#include "utils/player.h"

size_t GetPlayerCount(const linked_list_player *list) {
	size_t count = 0;
	while (list != NULL) {
		count++;
		list = list->next;
	}
	return count;
}


char GetPlayerType(const Player *p) {
	return p->type == PlayerType::Human ? 'H' : 'R';
}


linked_list_player *FindPlayerBefore(linked_list_player *list, uint32_t current_number) {
	if (current_number == 0)
		current_number = (uint32_t)GetPlayerCount(list) - 1;
	else
		current_number--;
	for (auto cursor = list; cursor != NULL; cursor = cursor->next) {
		if (cursor->player->number == current_number) return cursor;
	}
}

void AddPlayer(linked_list_player **list, PlayerType type, uint32_t number) {
	Player *p = new Player;
	p->type = type;
	p->number = number;
	p->quart_singe = 0;

	linked_list_player **cursor = list;
	while (*cursor != NULL) {
		cursor = &(*cursor)->next;
	}

	*cursor = new linked_list_player;
	(*cursor)->player = p;
	(*cursor)->next = NULL;
}

void ReadPlayers(linked_list_player **players, char **argv) {
	uint32_t players_count = 0;

	for (uint32_t i = 0; argv[1][i] != '\0'; i++) {
		PlayerType type;
		if (argv[1][i] == 'H') {
			type = PlayerType::Human;
		}
		else if (argv[1][i] == 'R') {
			type = PlayerType::Bot;
		}
		else {
			std::cout << std::endl << "Mauvais type de joueur saisi.";
			exit(EXIT_FAILURE);
		}
		AddPlayer(players, type, players_count);
		players_count++;
	}

	if (players_count < 2) {
		std::cout << std::endl << "Le jeu ne peut commencer qu'avec un minimum de 2 joueurs.";
		exit(EXIT_FAILURE);
	}
}


void PrintPlayers(const linked_list_player *list) {
	for (auto cursor = list; cursor != NULL; cursor = cursor->next) {
		std::cout << "Type : " << (int)cursor->player->type;
		std::cout << " | Quart : " << (int)cursor->player->quart_singe;
		std::cout << " | Number : " << cursor->player->number << std::endl;
	}
}
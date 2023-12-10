#pragma once
#pragma warning(disable:4996)
#include <algorithm>
#include "dictionary.h"
#include "player.h"
#include "player_bot.h"

/**
 * @brief Structure de données représentant une partie de quart de singe.
 *
 * @field players Pointeur vers la tête de la liste chaînée de joueurs.
 * @field dictionary Pointeur vers la tête de la liste chaînée de mots du dictionnaire.
 * @field char_count Nombre de caractères de la chaîne `current_word`.
 * @field current_word Chaîne de caractères représentant le mot en cours de construction.
 * @field round_done Indique si le tour de jeu est terminé.
 * @field game_done Indique si la partie est terminée.
 */
struct Game {
	linked_list_player *players;
	linked_list_dict *dictionary;
	uint32_t char_count;
	char *current_word;
	bool round_done;
	bool game_done;
};

/**
 * @brief Charge une partie de quart de singe.
 *
 * @param game Pointeur vers la structure de données représentant la partie à charger.
 * @param argv Tableau de chaînes de caractères passé en argument du programme principal.
 */
void GameLoad(Game *&game, char **argv);

/**
 * @brief Affiche l'état du quart de singe de chaque joueur et retourne si la partie est terminée.
 *
 * @param game Pointeur vers la structure de données représentant la partie en cours.
 * @param do_print Booléen indiquant si l'état du quart de singe doit être affiché ou non.
 * @return Booléen indiquant si la partie est terminée ou non.
 */
bool PrintSinge(Game *game, bool do_print);

/**
 * @brief Libère la mémoire utilisée par les dictionnaires, les joueurs et le jeu.
 *
 * @param game Le jeu en cours.
 */
void FreeMemory(Game *game);

/**
 * @brief Permet à un joueur de deviner un mot dans un jeu.
 *
 * @param game Pointeur de référence sur un objet `Game` contenant des informations sur l'état actuel du jeu.
 * @param cursor Pointeur de référence sur un élément de la liste chaînée des joueurs, contenant des informations sur le joueur actuellement en train de jouer.
 *
 * @return Booléen indiquant si la partie est terminée ou non.
 */
bool WordGuess(Game *&game, linked_list_player *&cursor);

/**
 * @brief Ajoute une lettre au mot actuellement à deviner dans le jeu et vérifie si le mot complet est présent dans le dictionnaire.
 *
 * @param game Pointeur de référence sur un objet `Game` contenant des informations sur l'état actuel du jeu.
 * @param cursor Pointeur de référence sur un élément de la liste chaînée des joueurs, contenant des informations sur le joueur actuellement en train de jouer.
 * @param c Lettre à ajouter au mot actuel.
 *
 * @return Booléen indiquant si le mot est complet et présent dans le dictionnaire.
 */
bool NewLetter(Game *&game, linked_list_player *&cursor, char c);

/**
 * @brief Boucle principale du jeu. Fait jouer chaque joueur à tour de rôle jusqu'à ce que la partie soit terminée.
 *
 * @param game Pointeur sur un objet `Game` contenant des informations sur l'état actuel du jeu.
 */
void GameLoop(Game *game);
#pragma once
#pragma warning(disable:4996)
#include <algorithm>
#include "dictionary.h"
#include "player.h"
#include "player_bot.h"

/**
 * @brief Structure de donn�es repr�sentant une partie de quart de singe.
 *
 * @field players Pointeur vers la t�te de la liste cha�n�e de joueurs.
 * @field dictionary Pointeur vers la t�te de la liste cha�n�e de mots du dictionnaire.
 * @field char_count Nombre de caract�res de la cha�ne `current_word`.
 * @field current_word Cha�ne de caract�res repr�sentant le mot en cours de construction.
 * @field round_done Indique si le tour de jeu est termin�.
 * @field game_done Indique si la partie est termin�e.
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
 * @param game Pointeur vers la structure de donn�es repr�sentant la partie � charger.
 * @param argv Tableau de cha�nes de caract�res pass� en argument du programme principal.
 */
void GameLoad(Game *&game, char **argv);

/**
 * @brief Affiche l'�tat du quart de singe de chaque joueur et retourne si la partie est termin�e.
 *
 * @param game Pointeur vers la structure de donn�es repr�sentant la partie en cours.
 * @param do_print Bool�en indiquant si l'�tat du quart de singe doit �tre affich� ou non.
 * @return Bool�en indiquant si la partie est termin�e ou non.
 */
bool PrintSinge(Game *game, bool do_print);

/**
 * @brief Lib�re la m�moire utilis�e par les dictionnaires, les joueurs et le jeu.
 *
 * @param game Le jeu en cours.
 */
void FreeMemory(Game *game);

/**
 * @brief Permet � un joueur de deviner un mot dans un jeu.
 *
 * @param game Pointeur de r�f�rence sur un objet `Game` contenant des informations sur l'�tat actuel du jeu.
 * @param cursor Pointeur de r�f�rence sur un �l�ment de la liste cha�n�e des joueurs, contenant des informations sur le joueur actuellement en train de jouer.
 *
 * @return Bool�en indiquant si la partie est termin�e ou non.
 */
bool WordGuess(Game *&game, linked_list_player *&cursor);

/**
 * @brief Ajoute une lettre au mot actuellement � deviner dans le jeu et v�rifie si le mot complet est pr�sent dans le dictionnaire.
 *
 * @param game Pointeur de r�f�rence sur un objet `Game` contenant des informations sur l'�tat actuel du jeu.
 * @param cursor Pointeur de r�f�rence sur un �l�ment de la liste cha�n�e des joueurs, contenant des informations sur le joueur actuellement en train de jouer.
 * @param c Lettre � ajouter au mot actuel.
 *
 * @return Bool�en indiquant si le mot est complet et pr�sent dans le dictionnaire.
 */
bool NewLetter(Game *&game, linked_list_player *&cursor, char c);

/**
 * @brief Boucle principale du jeu. Fait jouer chaque joueur � tour de r�le jusqu'� ce que la partie soit termin�e.
 *
 * @param game Pointeur sur un objet `Game` contenant des informations sur l'�tat actuel du jeu.
 */
void GameLoop(Game *game);
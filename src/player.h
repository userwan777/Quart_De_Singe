#pragma once
#pragma warning(disable:4996)
#include <cstddef>
#include <stdint.h>
#include <iostream>


/**
 * @brief �num�ration des types de joueur.
 */
enum class PlayerType {
	Human,
	Bot
};


/**
 * @brief Structure repr�sentant un joueur.
 * @field quart_singe Quart de singe associ� au joueur.
 * @field number Num�ro du joueur.
 * @field type Type de joueur.
 */
struct Player {
	char quart_singe;
	uint32_t number;
	PlayerType type;
};


/**
 * @brief Structure repr�sentant une liste cha�n�e de joueurs.
 * @field player Pointeur vers un joueur.
 * @field next Pointeur vers l'�l�ment suivant de la liste cha�n�e.
 */
struct linked_list_player {
	Player *player;
	linked_list_player *next;
};

/**
 * @brief Calcule le nombre de joueurs dans une liste cha�n�e.
 *
 * @param list Pointeur vers la t�te de la liste cha�n�e.
 * @return Le nombre de joueurs dans la liste cha�n�e.
 *
 * La fonction parcourt la liste cha�n�e et incr�mente un compteur pour chaque noeud rencontr�. La valeur du compteur
 * est retourn�e � la fin de la fonction.
 */
size_t GetPlayerCount(const linked_list_player *list);

/**
 * @brief Obtient le type de joueur sous forme de caract�re.
 *
 * @param p Pointeur vers le joueur.
 * @return 'H' si le joueur est de type Human, 'R' si le joueur est de type Bot.
 *
 * La fonction compare la valeur du champ `type` du joueur et retourne un caract�re en fonction du type de joueur.
 */
char GetPlayerType(const Player *p);

/**
 * @brief Trouve le n�ud dans une liste cha�n�e de joueurs contenant un joueur avec un num�ro sp�cifique.
 *
 * @param list Pointeur vers la t�te de la liste cha�n�e.
 * @param current_number Le num�ro du joueur � trouver.
 * @return Pointeur vers le n�ud contenant le joueur avec le num�ro donn�, ou `NULL` si aucun tel joueur n'a �t� trouv�.
 *
 * La fonction parcourt la liste cha�n�e et compare le champ `number` de chaque joueur avec le num�ro donn�. Si une
 * correspondance est trouv�e, la fonction retourne un pointeur vers le noeud contenant le joueur. Si la fin de la liste
 * est atteinte sans trouver de correspondance, la fonction retourne `NULL`.
 */
linked_list_player *FindPlayerBefore(linked_list_player *list, uint32_t current_number);

/**
 * @brief Ajoute un nouveau joueur � une liste cha�n�e de joueurs.
 *
 * @param list Pointeur vers la t�te de la liste cha�n�e.
 * @param type Le type de joueur (Human ou Bot).
 * @param number Le num�ro du joueur.
 *
 * La fonction cr�e un nouveau joueur et initialise ses champs avec les valeurs donn�es. Elle trouve ensuite le dernier
 * noeud de la liste cha�n�e et ajoute le nouveau joueur � la liste.
 */
void AddPlayer(linked_list_player **list, PlayerType type, uint32_t number);

/**
 * @brief Lit et analyse les informations sur les joueurs � partir des arguments de la ligne de commande.
 *
 * @param players Pointeur vers la t�te de la liste cha�n�e de joueurs.
 * @param argv Tableau d'arguments de la ligne de commande.
 *
 * La fonction lit les informations sur les joueurs � partir du premier �l�ment du tableau `argv`. La cha�ne est
 * attendue sous la forme d'une s�quence de caract�res 'H' ou 'R', repr�sentant des joueurs humains ou robotiques,
 * respectivement. Pour chaque caract�re, la fonction cr�e un nouveau joueur avec le type correspondant et l'ajoute �
 * la liste cha�n�e. Si un caract�re non valide est rencontr�, la fonction sort avec un message d'erreur. Si la
 * cha�ne contient moins de deux caract�res, la fonction sort �galement avec un message d'erreur.
 */
void ReadPlayers(linked_list_player **players, char **argv);

/**
 * @brief Affiche les informations sur les joueurs contenus dans une liste cha�n�e.
 *
 * @param list Pointeur vers la t�te de la liste cha�n�e de joueurs.
 *
 * La fonction parcourt la liste cha�n�e et affiche les informations sur chaque joueur : son type (humain ou robot),
 * son quart de singe et son num�ro.
 */
void PrintPlayers(const linked_list_player *list);
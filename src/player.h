#pragma once
#pragma warning(disable:4996)
#include <cstddef>
#include <stdint.h>
#include <iostream>


/**
 * @brief Énumération des types de joueur.
 */
enum class PlayerType {
	Human,
	Bot
};


/**
 * @brief Structure représentant un joueur.
 * @field quart_singe Quart de singe associé au joueur.
 * @field number Numéro du joueur.
 * @field type Type de joueur.
 */
struct Player {
	char quart_singe;
	uint32_t number;
	PlayerType type;
};


/**
 * @brief Structure représentant une liste chaînée de joueurs.
 * @field player Pointeur vers un joueur.
 * @field next Pointeur vers l'élément suivant de la liste chaînée.
 */
struct linked_list_player {
	Player *player;
	linked_list_player *next;
};

/**
 * @brief Calcule le nombre de joueurs dans une liste chaînée.
 *
 * @param list Pointeur vers la tête de la liste chaînée.
 * @return Le nombre de joueurs dans la liste chaînée.
 *
 * La fonction parcourt la liste chaînée et incrémente un compteur pour chaque noeud rencontré. La valeur du compteur
 * est retournée à la fin de la fonction.
 */
size_t GetPlayerCount(const linked_list_player *list);

/**
 * @brief Obtient le type de joueur sous forme de caractère.
 *
 * @param p Pointeur vers le joueur.
 * @return 'H' si le joueur est de type Human, 'R' si le joueur est de type Bot.
 *
 * La fonction compare la valeur du champ `type` du joueur et retourne un caractère en fonction du type de joueur.
 */
char GetPlayerType(const Player *p);

/**
 * @brief Trouve le nœud dans une liste chaînée de joueurs contenant un joueur avec un numéro spécifique.
 *
 * @param list Pointeur vers la tête de la liste chaînée.
 * @param current_number Le numéro du joueur à trouver.
 * @return Pointeur vers le nœud contenant le joueur avec le numéro donné, ou `NULL` si aucun tel joueur n'a été trouvé.
 *
 * La fonction parcourt la liste chaînée et compare le champ `number` de chaque joueur avec le numéro donné. Si une
 * correspondance est trouvée, la fonction retourne un pointeur vers le noeud contenant le joueur. Si la fin de la liste
 * est atteinte sans trouver de correspondance, la fonction retourne `NULL`.
 */
linked_list_player *FindPlayerBefore(linked_list_player *list, uint32_t current_number);

/**
 * @brief Ajoute un nouveau joueur à une liste chaînée de joueurs.
 *
 * @param list Pointeur vers la tête de la liste chaînée.
 * @param type Le type de joueur (Human ou Bot).
 * @param number Le numéro du joueur.
 *
 * La fonction crée un nouveau joueur et initialise ses champs avec les valeurs données. Elle trouve ensuite le dernier
 * noeud de la liste chaînée et ajoute le nouveau joueur à la liste.
 */
void AddPlayer(linked_list_player **list, PlayerType type, uint32_t number);

/**
 * @brief Lit et analyse les informations sur les joueurs à partir des arguments de la ligne de commande.
 *
 * @param players Pointeur vers la tête de la liste chaînée de joueurs.
 * @param argv Tableau d'arguments de la ligne de commande.
 *
 * La fonction lit les informations sur les joueurs à partir du premier élément du tableau `argv`. La chaîne est
 * attendue sous la forme d'une séquence de caractères 'H' ou 'R', représentant des joueurs humains ou robotiques,
 * respectivement. Pour chaque caractère, la fonction crée un nouveau joueur avec le type correspondant et l'ajoute à
 * la liste chaînée. Si un caractère non valide est rencontré, la fonction sort avec un message d'erreur. Si la
 * chaîne contient moins de deux caractères, la fonction sort également avec un message d'erreur.
 */
void ReadPlayers(linked_list_player **players, char **argv);

/**
 * @brief Affiche les informations sur les joueurs contenus dans une liste chaînée.
 *
 * @param list Pointeur vers la tête de la liste chaînée de joueurs.
 *
 * La fonction parcourt la liste chaînée et affiche les informations sur chaque joueur : son type (humain ou robot),
 * son quart de singe et son numéro.
 */
void PrintPlayers(const linked_list_player *list);
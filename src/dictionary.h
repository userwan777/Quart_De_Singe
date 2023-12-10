#pragma once
#pragma warning(disable:4996)
#include <string.h>
#include <iostream>
#include <fstream>

/**
 * @brief Taille maximale d'un mot dans la langue.
 */
const enum {
	LANG_WORD_MAX_SIZE = 25
};

/**
 * @brief Un noeud de liste chaînée pour stocker un mot.
 *
 * @field item Le mot stocké dans le noeud.
 * @field next Pointeur vers le prochain noeud de la liste.
 */
struct linked_list_dict {
	char *item;
	linked_list_dict *next;
};


/**
 * @brief Obtient la taille d'une liste chaînée de mots.
 *
 * @param list Pointeur vers la tête de la liste chaînée.
 * @return Le nombre de mots dans la liste.
 *
 * La fonction parcourt la liste chaînée et incrémente un compteur pour chaque élément. La valeur finale du
 * compteur est retournée comme étant la taille de la liste.
 */
size_t GetListSize(const linked_list_dict *list);

/**
 * @brief Vérifie si une liste chaînée de mots contient un mot particulier.
 *
 * @param list Pointeur vers la tête de la liste chaînée.
 * @param str Le mot à rechercher.
 * @return true si le mot est trouvé dans la liste, false sinon.
 *
 * La fonction parcourt la liste chaînée et compare chaque mot à la chaîne de recherche en utilisant la fonction
 * strcmp. Si une correspondance est trouvée, la fonction retourne true. Si la fin de la liste est atteinte sans
 * trouver de correspondance, la fonction retourne false.
 */
bool ListContains(const linked_list_dict *list, char *str);

/**
 * @brief Vérifie si un mot est cohérent avec le mot actuel.
 *
 * @param current_word Le mot actuel.
 * @param word Le mot à vérifier.
 * @return true si le mot est cohérent avec le mot actuel, false sinon.
 *
 * Un mot est considéré comme cohérent avec le mot actuel s'il est plus long que le mot actuel et s'il commence par
 * les mêmes caractères que le mot actuel.
 */
bool isWordCoherent(char *current_word, char *word);

/**
 * @brief Affiche les mots dans une liste chaînée de mots.
 *
 * @param list Pointeur vers la tête de la liste chaînée.
 *
 * La fonction parcourt la liste chaînée et affiche le mot stocké dans chaque nœud sur la sortie standard.
 */
void ListPrintItems(const linked_list_dict *list);

/**
 * @brief Lit un fichier dictionnaire et stocke les mots dans une liste chaînée.
 *
 * @param filename Le nom du fichier dictionnaire.
 * @return Pointeur vers la tête de la liste chaînée de mots.
 *
 * La fonction ouvre le fichier dictionnaire et lit chaque ligne, en la stockant comme mot dans un nouveau nœud de la
 * liste chaînée. Si la ligne est plus courte ou égale à 3 caractères, elle est ignorée. La fonction retourne un
 * pointeur vers la tête de la liste chaînée.
 */
linked_list_dict *ReadDictionary(const char *filename);

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
 * @brief Un noeud de liste cha�n�e pour stocker un mot.
 *
 * @field item Le mot stock� dans le noeud.
 * @field next Pointeur vers le prochain noeud de la liste.
 */
struct linked_list_dict {
	char *item;
	linked_list_dict *next;
};


/**
 * @brief Obtient la taille d'une liste cha�n�e de mots.
 *
 * @param list Pointeur vers la t�te de la liste cha�n�e.
 * @return Le nombre de mots dans la liste.
 *
 * La fonction parcourt la liste cha�n�e et incr�mente un compteur pour chaque �l�ment. La valeur finale du
 * compteur est retourn�e comme �tant la taille de la liste.
 */
size_t GetListSize(const linked_list_dict *list);

/**
 * @brief V�rifie si une liste cha�n�e de mots contient un mot particulier.
 *
 * @param list Pointeur vers la t�te de la liste cha�n�e.
 * @param str Le mot � rechercher.
 * @return true si le mot est trouv� dans la liste, false sinon.
 *
 * La fonction parcourt la liste cha�n�e et compare chaque mot � la cha�ne de recherche en utilisant la fonction
 * strcmp. Si une correspondance est trouv�e, la fonction retourne true. Si la fin de la liste est atteinte sans
 * trouver de correspondance, la fonction retourne false.
 */
bool ListContains(const linked_list_dict *list, char *str);

/**
 * @brief V�rifie si un mot est coh�rent avec le mot actuel.
 *
 * @param current_word Le mot actuel.
 * @param word Le mot � v�rifier.
 * @return true si le mot est coh�rent avec le mot actuel, false sinon.
 *
 * Un mot est consid�r� comme coh�rent avec le mot actuel s'il est plus long que le mot actuel et s'il commence par
 * les m�mes caract�res que le mot actuel.
 */
bool isWordCoherent(char *current_word, char *word);

/**
 * @brief Affiche les mots dans une liste cha�n�e de mots.
 *
 * @param list Pointeur vers la t�te de la liste cha�n�e.
 *
 * La fonction parcourt la liste cha�n�e et affiche le mot stock� dans chaque n�ud sur la sortie standard.
 */
void ListPrintItems(const linked_list_dict *list);

/**
 * @brief Lit un fichier dictionnaire et stocke les mots dans une liste cha�n�e.
 *
 * @param filename Le nom du fichier dictionnaire.
 * @return Pointeur vers la t�te de la liste cha�n�e de mots.
 *
 * La fonction ouvre le fichier dictionnaire et lit chaque ligne, en la stockant comme mot dans un nouveau n�ud de la
 * liste cha�n�e. Si la ligne est plus courte ou �gale � 3 caract�res, elle est ignor�e. La fonction retourne un
 * pointeur vers la t�te de la liste cha�n�e.
 */
linked_list_dict *ReadDictionary(const char *filename);

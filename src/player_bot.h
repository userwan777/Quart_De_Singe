#pragma once
#pragma warning(disable:4996)
#include "utils/dictionary.h"
#include <string.h>
#include <iostream>

/**
 * @brief Modifie l'alphabet en enlevant un caract�re choisi au hasard ou en l'�changeant avec le dernier caract�re.
 *
 * @param alphabet Pointeur vers la cha�ne de l'alphabet. Elle est mise � jour en place.
 * @return Le caract�re enlev� ou �chang�.
 *
 * La fonction g�n�re un index al�atoire compris entre 0 et la longueur de la cha�ne de l'alphabet (exclusivement).
 * Si l'index g�n�r� correspond au dernier caract�re de l'alphabet, le caract�re est enlev� de l'alphabet. Sinon,
 * le caract�re � l'index g�n�r� est �chang� avec le dernier caract�re et ensuite enlev� de l'alphabet. La cha�ne
 * de l'alphabet est r�allou�e � sa nouvelle taille (un caract�re de moins).
 */
char UpdateAlphabet(char *&alphabet);

/**
 * @brief Trouve la prochaine lettre qui peut �tre ajout�e au mot actuel pour former un mot coh�rent.
 *
 * @param words Pointeur vers la t�te de la liste cha�n�e des mots.
 * @param current_word Le mot actuel.
 * @return La prochaine lettre coh�rente, ou '?' si aucune lettre coh�rente n'a �t� trouv�e.
 *
 * La fonction cr�e une cha�ne d'alphabet contenant toutes les lettres de 'A' � 'Z' et un caract�re nul. Elle met
 * ensuite � jour r�p�titivement l'alphabet (en enlevant ou en �changeant un caract�re choisi au hasard) et v�rifie
 * si le caract�re mis � jour de l'alphabet peut �tre ajout� au mot actuel pour former un mot coh�rent (selon la
 * fonction isWordCoherent). Si une lettre coh�rente est trouv�e, elle est retourn�e. Si l'alphabet devient vide et
 * qu'aucune lettre coh�rente n'a �t� trouv�e, la fonction retourne '?'.
 */
char FindCoherentLetter(linked_list_dict *words, char *current_word);

/**
 * @brief V�rifie si le choix de lettre de l'IA est valide.
 *
 * @param words Pointeur vers la t�te de la liste cha�n�e des mots.
 * @param current_word Le mot actuel.
 * @return La lettre valide choisie par l'IA, ou '?' si aucune lettre valide n'a �t� trouv�e.
 *
 * La fonction appelle d'abord la fonction FindCoherentLetter pour trouver une lettre coh�rente � ajouter au mot
 * actuel. Elle v�rifie ensuite si le mot r�sultant est dans la liste cha�n�e de mots. Si c'est le cas, la fonction
 * retourne '?'. Sinon, elle retourne la lettre valide choisie par l'IA.
 */
char BotChoiceCheck(linked_list_dict *words, char *current_word);

/**
 * @brief Fait choisir une lettre � l'IA pour ajouter au mot actuel.
 *
 * @param words Pointeur vers la t�te de la liste cha�n�e des mots.
 * @param current_word Le mot actuel.
 * @return La lettre choisie.
 *
 * Si le mot actuel a moins de 2 caract�res, la fonction appelle la fonction BotChoiceCheck pour choisir une lettre.
 * Sinon, elle retourne le r�sultat de l'appel de la fonction BotChoiceCheck.
 */
char BotChoose(linked_list_dict *words, char *current_word);

/**
 * @brief Fait deviner le mot suivant par l'IA.
 *
 * @param words Pointeur vers la t�te de la liste cha�n�e des mots.
 * @param current_word Le mot actuel.
 * @return Le mot devin�.
 *
 * La fonction parcourt la liste cha�n�e de mots et v�rifie si l'un d'entre eux est coh�rent avec le mot actuel
 * (selon la fonction isWordCoherent). Si un mot coh�rent est trouv�, il est retourn�. Si aucun mot coh�rent n'est
 * trouv�, le mot actuel est retourn�.
 */
char *BotGuessWord(linked_list_dict *words, char *current_word);

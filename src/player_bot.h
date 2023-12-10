#pragma once
#pragma warning(disable:4996)
#include "utils/dictionary.h"
#include <string.h>
#include <iostream>

/**
 * @brief Modifie l'alphabet en enlevant un caractère choisi au hasard ou en l'échangeant avec le dernier caractère.
 *
 * @param alphabet Pointeur vers la chaîne de l'alphabet. Elle est mise à jour en place.
 * @return Le caractère enlevé ou échangé.
 *
 * La fonction génère un index aléatoire compris entre 0 et la longueur de la chaîne de l'alphabet (exclusivement).
 * Si l'index généré correspond au dernier caractère de l'alphabet, le caractère est enlevé de l'alphabet. Sinon,
 * le caractère à l'index généré est échangé avec le dernier caractère et ensuite enlevé de l'alphabet. La chaîne
 * de l'alphabet est réallouée à sa nouvelle taille (un caractère de moins).
 */
char UpdateAlphabet(char *&alphabet);

/**
 * @brief Trouve la prochaine lettre qui peut être ajoutée au mot actuel pour former un mot cohérent.
 *
 * @param words Pointeur vers la tête de la liste chaînée des mots.
 * @param current_word Le mot actuel.
 * @return La prochaine lettre cohérente, ou '?' si aucune lettre cohérente n'a été trouvée.
 *
 * La fonction crée une chaîne d'alphabet contenant toutes les lettres de 'A' à 'Z' et un caractère nul. Elle met
 * ensuite à jour répétitivement l'alphabet (en enlevant ou en échangeant un caractère choisi au hasard) et vérifie
 * si le caractère mis à jour de l'alphabet peut être ajouté au mot actuel pour former un mot cohérent (selon la
 * fonction isWordCoherent). Si une lettre cohérente est trouvée, elle est retournée. Si l'alphabet devient vide et
 * qu'aucune lettre cohérente n'a été trouvée, la fonction retourne '?'.
 */
char FindCoherentLetter(linked_list_dict *words, char *current_word);

/**
 * @brief Vérifie si le choix de lettre de l'IA est valide.
 *
 * @param words Pointeur vers la tête de la liste chaînée des mots.
 * @param current_word Le mot actuel.
 * @return La lettre valide choisie par l'IA, ou '?' si aucune lettre valide n'a été trouvée.
 *
 * La fonction appelle d'abord la fonction FindCoherentLetter pour trouver une lettre cohérente à ajouter au mot
 * actuel. Elle vérifie ensuite si le mot résultant est dans la liste chaînée de mots. Si c'est le cas, la fonction
 * retourne '?'. Sinon, elle retourne la lettre valide choisie par l'IA.
 */
char BotChoiceCheck(linked_list_dict *words, char *current_word);

/**
 * @brief Fait choisir une lettre à l'IA pour ajouter au mot actuel.
 *
 * @param words Pointeur vers la tête de la liste chaînée des mots.
 * @param current_word Le mot actuel.
 * @return La lettre choisie.
 *
 * Si le mot actuel a moins de 2 caractères, la fonction appelle la fonction BotChoiceCheck pour choisir une lettre.
 * Sinon, elle retourne le résultat de l'appel de la fonction BotChoiceCheck.
 */
char BotChoose(linked_list_dict *words, char *current_word);

/**
 * @brief Fait deviner le mot suivant par l'IA.
 *
 * @param words Pointeur vers la tête de la liste chaînée des mots.
 * @param current_word Le mot actuel.
 * @return Le mot deviné.
 *
 * La fonction parcourt la liste chaînée de mots et vérifie si l'un d'entre eux est cohérent avec le mot actuel
 * (selon la fonction isWordCoherent). Si un mot cohérent est trouvé, il est retourné. Si aucun mot cohérent n'est
 * trouvé, le mot actuel est retourné.
 */
char *BotGuessWord(linked_list_dict *words, char *current_word);

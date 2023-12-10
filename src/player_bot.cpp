#include "utils/player_bot.h"

char UpdateAlphabet(char *&alphabet) {
	size_t len = strlen(alphabet);
	uint32_t random = rand() % len;

	char c = alphabet[random];
	memmove(alphabet + random, alphabet + random + 1, len - random);
	alphabet[len - 1] = '\0';
	return c;
}


char FindCoherentLetter(linked_list_dict *words, char *current_word) {
	char *alphabet = new char[27];

	int i = 0;
	for (int a = 'A'; a <= 'Z'; a++) {
		alphabet[i] = a;
		i++;
	}

	alphabet[26] = '\0';

	while (strlen(alphabet) != 0) {
		char c = UpdateAlphabet(alphabet);

		for (auto cursor = words; cursor != NULL; cursor = cursor->next) {
			if (cursor->item[strlen(current_word)] != c)
				continue;
			if (isWordCoherent(current_word, cursor->item))
				return c;
		}
	}
	return '?';
}

char BotChoiceCheck(linked_list_dict *words, char *current_word) {
	char c = FindCoherentLetter(words, current_word);

	uint32_t word_len = strlen(current_word);
	char *c_word = new char[word_len + 2];
	strcpy(c_word, current_word);
	c_word[word_len] = c;
	c_word[word_len + 1] = '\0';

	if (ListContains(words, c_word)) {
		c = '?';
	}

	delete[] c_word;
	return c;
}


char BotChoose(linked_list_dict *words, char *current_word) {
	if (strlen(current_word) <= 2)
		return BotChoiceCheck(words, current_word);
	else {
		return BotChoiceCheck(words, current_word);
	}
}

char *BotGuessWord(linked_list_dict *words, char *current_word) {
	for (auto cursor = words; cursor != NULL; cursor = cursor->next) {
		if (isWordCoherent(current_word, cursor->item)) {
			return cursor->item;
		}
	}
	return current_word;
}
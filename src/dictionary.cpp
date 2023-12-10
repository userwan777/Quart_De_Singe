#include "utils/dictionary.h"

size_t GetListSize(const linked_list_dict *list) {
	size_t count = 0;
	while (list != NULL) {
		count++;
		list = list->next;
	}
	return count;
}

bool ListContains(const linked_list_dict *list, char *str) {
	for (auto cursor = list; cursor != NULL; cursor = cursor->next) {
		if (strcmp(str, cursor->item) == 0)
			return true;
	}
	return false;
}

linked_list_dict *AddWord(linked_list_dict *head, char *item) {
	linked_list_dict *new_node = new linked_list_dict;
	new_node->item = item;
	new_node->next = NULL;

	if (head == NULL) {
		return new_node;
	}
	else {
		linked_list_dict *cursor = head;
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}
		cursor->next = new_node;
		return head;
	}
}


bool isWordCoherent(char *current_word, char *word) {
	return strlen(word) > strlen(current_word) &&
		strncmp(current_word, word, strlen(current_word)) == 0;
}

void ListPrintItems(const linked_list_dict *list) {
	for (auto cursor = list; cursor != NULL; cursor = cursor->next) {
		std::cout << cursor->item << std::endl;
	}
}

linked_list_dict *ReadDictionary(const char *filename) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cout << "Le fichier dictionnaire " << filename << " n'a pas pu etre ouvert." << std::endl;
		exit(EXIT_FAILURE);
	}

	char str[LANG_WORD_MAX_SIZE + 1];
	linked_list_dict *words = NULL;
	linked_list_dict *cursor = NULL;

	while (file.peek() != EOF) {
		file.getline(str, LANG_WORD_MAX_SIZE + 1, '\n');
		if (strlen(str) + 1 <= 3) continue;

		auto entry = new linked_list_dict;
		char *word = new char[strlen(str) + 1];
		strcpy(word, str);
		entry->item = word;
		entry->next = NULL;

		if (words == NULL) {
			words = entry;
			cursor = entry;
		}
		else {
			cursor->next = entry;
			cursor = entry;
		}
	}

	file.close();
	return words;
}
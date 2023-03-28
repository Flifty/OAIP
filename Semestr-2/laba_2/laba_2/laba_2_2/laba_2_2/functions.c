#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"

extern int words_amount;
extern int fl;

void replacement_words(words** word, FILE* comp) {
	int amount = 0;
	int letter = 0;
	int max = 1000;
	char* word_c = (char*)calloc(30, sizeof(char));
	char s[1000];
	while (amount != 3) {

		if (words_amount % 1000 == 0) {
			max += 1000;
			(*word) = (words*)realloc((*word), max * sizeof(words));
		}
		fgets(s, 1000, comp);
		amount = 0;
		for (int i = 0; i < strlen(s); i++) {

			word_c[letter] = s[i];
			letter++;
			if (s[i + 1] == ' ' || s[i + 1] == '\n') {
				amount++;
				if (amount > 2) {
					break;
				}
				letter = 0;
				if (words_amount == 1040) {
					int b = 0;
				}
				if (amount == 1) {
					strcpy((*word)[words_amount].A, word_c);
				}
				if (amount == 2) {
					strcpy((*word)[words_amount].B, word_c);
					words_amount++;
				}
				word_c = (char*)calloc(30, sizeof(char));
				i++;
			}
		}

	}
	fseek(comp, (-1) * strlen(s) - 1, SEEK_CUR);
	words_amount--;
}

void clear_word(char** word) {
	int j = 0;
	for (int i = 0; (*word)[i] != '\0'; i++) {
		int a = ispunct((*word)[i]);
		if (a == 0) {
			(*word)[j] = (*word)[i];
			j++;
		}
		else {
			fl++;
		}
	}
	(*word)[j] = '\0';

}

void uncompressing(words* word, FILE* comp) {
	char* word_c = (char*)calloc(30, sizeof(char));
	char s[15000];
	FILE* uncomp;
	fopen_s(&uncomp, "C:\\Users\\Danya\\Учеба\\Семестр_2\\ОАиП\\compress\\uncompress_file.txt", "wt+");
	while (!feof(comp)) {
		fgets(s, 15000, comp);
		int i = 0;
		int end = 0;
		int letter = 0;
		int flag = 0;
		int str_len = strlen(s);
		while (s[i] != '\n' && s[i] != '\0') {
			word_c[letter] = s[i];

			flag = 0;
			if (s[i + 1] == ' ' || s[i + 1] == '\n') {
				letter = -1;
				fl = 0;
				clear_word(&word_c);

				int len_c = strlen(word_c);
				for (int j = 0; j < words_amount; j++) {

					if (strcmp(word_c, word[j].A) == 0) {
						if (fl >= 1) {
							i -= fl;
						}
						strcpy(word_c, word[j].B);
						flag++;
						int  len1 = strlen(word_c);
						for (int y = 0; y < len1; y++) {
							s[i - len_c + y + 1] = word_c[y];
						}
						str_len = str_len - len_c + len1;
						for (int y = i - (len_c - len1) + 1; y < str_len; y++) {
							s[y] = s[y + len_c - len1];
						}
						i = i - len_c + len1 + 1;
						end = j + 1;
						word_c = (char*)calloc(30, sizeof(char));
						break;
					}
					else

						if (strcmp(word_c, word[j].B) == 0) {
							if (fl >= 1) {
								i -= fl;
							}
							flag++;
							strcpy(word_c, word[j].A);
							int  len1 = strlen(word_c);
							str_len = str_len + len1 - len_c;
							s[str_len] = '\0';
							for (int y = str_len - 1; y > i + len1 - len_c; y--) {
								s[y] = s[y - len1 + len_c];
							}
							for (int y = 0; y < len1; y++) {
								s[i - len_c + y + 1] = word_c[y];
							}
							i = i + len1 - len_c + 1;
							end = j + 1;
							word_c = (char*)calloc(30, sizeof(char));
							break;
						}
					end = j + 1;
				}
				if (flag == 0) {
					word_c = (char*)calloc(30, sizeof(char));
					i++;
				}
			}
			i++;
			letter++;

		}
		s[str_len] = '\0';
		fputs(s, uncomp);
	}
	free(word_c);

}
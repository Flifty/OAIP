#include "functions.h"

int words_amount = 0;
int fl = 0;

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE* comp;
	fopen_s(&comp, "C:\\Users\\Danya\\Учеба\\Семестр_2\\ОАиП\\compress\\compress_file.txt", "rt+");
	if (comp == NULL) {
		printf("file cannot be read");
		exit(1);
	}
	fseek(comp, 0, SEEK_SET);
	words* word;
	word = (words*)calloc(1000, sizeof(words));

	replacement_words(&word, comp);

	uncompressing(word, comp);
}
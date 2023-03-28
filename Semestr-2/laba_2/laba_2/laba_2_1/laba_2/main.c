#include "functions.h"

int fl = 0;
int words_amount = 0;

int main() {
    setlocale(LC_ALL, "Rus");
    FILE* file = NULL;
    FILE* COMP_file = NULL;
    FILE* UNCOMP_file = NULL;
    fopen_s(&file, "C:\\Users\\Danya\\Учеба\\Семестр_2\\ОАиП\\compress\\file.txt", "rt+");
    if (file == NULL) {
        printf("File can not be open");
        return -1;
    }
    word_freq* words = NULL;
    stack* stack = NULL;
    find_words(file, &words, &stack);
    fseek(file, 0, SEEK_SET);
    sort_words(words);
    stack_inic(words, stack);
    compress(file, COMP_file, stack);
}
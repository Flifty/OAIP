#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"


extern int words_amount;
extern int fl;

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

void find_words(FILE* file, word_freq** words, stack** stackk) {
    int max = 1000;
    (*words) = (word_freq*)calloc(max, sizeof(word_freq));
    (*stackk) = (stack*)calloc(max, sizeof(stack));
    char* word;
    word = (char*)calloc(30, sizeof(char));
    while ((fscanf(file, "%s", word) == 1) && (!feof(file))) {
        clear_word(&word);
        int flag = 0;
        for (int i = 0; i < words_amount; i++) {
            if (!(strcmp(word, (*words)[i].word))) {
                flag = 1;
                (*words)[i].amount++;
                break;
            }
        }
        if (!flag) {
            strcpy((*words)[words_amount].word, word);
            // printf("%s\n", word);
            (*words)[words_amount].amount = 1;
            words_amount++;
        }
        if (words_amount % max == 0) {
            max += 1000;
            (*words) = (word_freq*)realloc((*words), max * sizeof(word_freq));
            (*stackk) = (stack*)realloc((*stackk), max * sizeof(stack));
        }
    }
}

int compare(const void* a, const void* b) {
    word_freq* pa = (word_freq*)a;
    word_freq* pb = (word_freq*)b;
    if (pa->amount < pb->amount) {
        return -1;
    }
    else if (pa->amount > pb->amount) {
        return 1;
    }
    if (strlen(pa->word) < strlen(pb->word)) {
        return -1;
    }
    else if (strlen(pa->word) > strlen(pb->word)) {
        return 1;
    }
}
void sort_words(word_freq* words) {
    //for (int i = 0; i < 10; i++) {
    //    printf("%d %s\n", words[i].amount, words[i].word);
    //}
    qsort(words, words_amount, sizeof(word_freq), (int (*)(const void*, const void*)) compare);
    //for (int i = 0; i < 10; i++) {
    //    printf("\n%d %s", words[i].amount, words[i].word);
    //}
}

void push(char* word, char* origin_word, int top) {
    if (top >= words_amount) {
        printf("stack overflow");
        exit(0);
    }
    strcpy(word, origin_word);
}

void stack_inic(word_freq* words, stack* stackk) {
    stackk->top_A = 0;
    stackk->top_B = 0;
    for (int i = 0; i < words_amount; i++) {
        if (strlen(words[i].word) > 4) {
            stackk[stackk->top_A].A = (char*)calloc(30, sizeof(char));
            push(stackk[stackk->top_A].A, words[i].word, stackk->top_A);
            stackk[stackk->top_A].freq_A = words[i].amount;
            stackk->top_A++;
        }
    }
    for (int i = words_amount - 1; i >= 0; i--) {
        if (strlen(words[i].word) <= 4 && strlen(words[i].word) > 0) {
            stackk[stackk->top_B].B = (char*)calloc(30, sizeof(char));
            push(stackk[stackk->top_B].B, words[i].word, stackk->top_B);
            stackk[stackk->top_B].freq_B = words[i].amount;
            stackk->top_B++;
        }
    }
}

void change_words(char* word, char* word2) {
    char c = '0';
    int a = strlen(word);
    for (int i = 0; i < strlen(word); i++) {
        int a = ispunct(word[i]);
        if (a != 0 || (word[i] == -85 || word[i] == -69 || word[i] == -123 || word[i] == -124 || word[i] == -109)) {
            c = word[i];
        }
    }
    a = strlen(word2);
    for (int i = 0; i < strlen(word2); i++) {
        word[i] = word2[i];
    }
    if (c != '0') {
        word[strlen(word2)] = c;
        word[strlen(word2) + 1] = '\0';
    }
    else {
        word[strlen(word2)] = '\0';
    }
}

void compress(FILE* file, FILE* COMP_file, stack* stackk) {
    fopen_s(&COMP_file, "C:\\Users\\Danya\\Учеба\\Семестр_2\\ОАиП\\compress\\compress_file.txt", "w+");
    int a = stackk->top_A;
    int b = stackk->top_B;
    while (a != 0 && b != 0) {
        a--;
        b--;
        if (stackk[b].freq_B > stackk[a].freq_A) {
            break;
        }
        fprintf(COMP_file, "%s %s\n", stackk[a].A, stackk[b].B);
    }
    int num = a;
    fseek(file, 0, SEEK_SET);
    int y = 0;
    char str[10000];
    char* word = (char*)calloc(30, sizeof(char));
    while (!feof(file)) {
        fgets(str, 10000, file);
        int i = 0;
        int end = 0;
        int letter = 0;
        int flag = 0;
        int str_len = strlen(str);
        while (str[i] != '\n' && str[i] != '\0') {
            word[letter] = str[i];

            flag = 0;
            if (str[i + 1] == ' ' || str[i + 1] == '\n') {
                letter = -1;
                fl = 0;
                clear_word(&word);

                int len_c = strlen(word);
                for (int j = num + 1; j < stackk->top_A; j++) {

                    if (strcmp(word, stackk[j].A) == 0) {
                        if (fl >= 1) {
                            i -= fl;
                        }
                        strcpy(word, stackk[stackk->top_B - (stackk->top_A - j)].B);
                        flag++;
                        int  len1 = strlen(word);
                        for (int y = 0; y < len1; y++) {
                            str[i - len_c + y + 1] = word[y];
                        }
                        str_len = str_len - len_c + len1;
                        for (int y = i - (len_c - len1) + 1; y < str_len; y++) {
                            str[y] = str[y + len_c - len1];
                        }
                        i = i - len_c + len1 + 1;
                        end = j + 1;
                        word = (char*)calloc(30, sizeof(char));
                        break;
                    }
                    else

                        if (strcmp(word, stackk[stackk->top_B - (stackk->top_A - j)].B) == 0) {
                            if (fl >= 1) {
                                i -= fl;
                            }
                            flag++;
                            strcpy(word, stackk[j].A);
                            int  len1 = strlen(word);
                            str_len = str_len + len1 - len_c;
                            str[str_len] = '\0';
                            for (int y = str_len - 1; y > i + len1 - len_c; y--) {
                                str[y] = str[y - len1 + len_c];
                            }
                            for (int y = 0; y < len1; y++) {
                                str[i - len_c + y + 1] = word[y];
                            }
                            i = i + len1 - len_c + 1;
                            end = j + 1;
                            word = (char*)calloc(30, sizeof(char));
                            break;
                        }
                    end = j + 1;
                }
                if (flag == 0) {
                    word = (char*)calloc(30, sizeof(char));
                    i++;
                }
            }
            i++;
            letter++;

        }
        str[str_len] = '\0';
        fputs(str, COMP_file);
    }
    free(word);


}
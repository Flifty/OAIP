#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

typedef struct {
	char word[30];
	int amount;
} word_freq;

typedef struct {
	char* A;
	char* B;
	int top_A;
	int top_B;
	int freq_A;
	int freq_B;
} stack;

void clear_word(char** word);
void find_words(FILE* file, word_freq** words, stack** stackk);
int compare(const void* a, const void* b);
void sort_words(word_freq* words);
void push(char* word, char* origin_word, int top);
void stack_inic(word_freq* words, stack* stackk);
void change_words(char* word, char* word2);
void file_compress(FILE* file, stack* stackk, FILE* COMP_file);
void compress(FILE* file, FILE* COMP_file, stack* stackk);

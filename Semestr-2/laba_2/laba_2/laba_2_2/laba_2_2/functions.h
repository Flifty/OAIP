#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

typedef struct {
	char A[30];
	char B[30];
} words;

void replacement_words(words** word, FILE* comp);
void clear_word(char** word);
void uncompressing(words* word, FILE* comp);

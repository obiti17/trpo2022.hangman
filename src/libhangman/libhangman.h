#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 8

void print(char* tmp_word, int num_hang, char* word);
void fileRead(char** dictionary, int mode);
void randWord(char** dictionary, char** word);
int searchLetter(
        char* word,
        char* tmp_word,
        char letter); // если буква найдена - возвращает
                      // позицию, если не найдена - (-1)
void helper();
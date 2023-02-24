#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void print();
void fileRead(char** dictionary, int mode);
void randWord(char** dictionary, char* word);
int searchLetter(char* word, char letter); // если буква найдена - возвращает
                                           // позицию, если не найдена - (-1)
void helper();
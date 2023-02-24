#include "libhangman.h"

void print()
{
}
void fileRead(char** dictionary, int mode)
{
    char* filename = malloc(30);
    switch (mode) {
    case 0:
        filename = "main.txt";
        break;
    case 1:
        filename = "countries.txt";
        break;
    case 2:
        filename = "animals.txt";
        break;
    case 3:
        filename = "plants.txt";
        break;
    }
    FILE* file = fopen(filename, "r");
    int i = 0, k = 0;
    char* buf = malloc(30);
    char sym;
    while (!feof(file)) {
        sym = fgetc(file);
        if (sym == ' ') {
            dictionary[i] = buf;
            i++;
            k = 0;
            buf = malloc(30);

        } else {
            buf[k] = sym;
            k++;
        }
    }
}
void randWord(char** dictionary, char* word)
{
    int randW = rand() % SIZE;
    word = dictionary[randW];
}
int searchLetter(char* word, char letter)
{
}
void helper()
{
    // printf("-c - режим Страны\n
    //  -a - режим Животные\n
    //  -p - режим Растения\n");
}
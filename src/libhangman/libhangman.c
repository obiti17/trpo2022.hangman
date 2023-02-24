#include <libhangman.h>

void print(char *tmp_word, int num_hang, char *word)
{
    printf ("\E[%d;%dH", 4, 20);
    printf("letter : %s\n", tmp_word);
    if (num_hang == 0) {
        printf ("\E[%d;%dH_", 3, 1);
    }
    if (num_hang >= 1) {
        printf ("\E[%d;%dH_", 3, 2);
    }
    if (num_hang >= 2) {
        printf ("\E[%d;%dH_", 3, 3);
    }
    if (num_hang >= 3) {
        printf ("\E[%d;%dH|", 4, 3);
    }
    if (num_hang >= 4) {
        printf ("\E[%d;%dH*", 5, 3);
    }
    if (num_hang >= 5) {
        printf ("\E[%d;%dH|", 6, 3);
    }
    if (num_hang >= 6) {
        printf ("\E[%d;%dH/", 6, 2);
    }
    if (num_hang >= 7) {
        printf ("\E[%d;%dH\\", 6, 4);
    }
    if (num_hang >= 8) {
        printf ("\E[%d;%dH/", 7, 2);
    }
    if (num_hang >= 9) {
        printf ("\E[%d;%dH\\", 7, 4);
    }
    if (num_hang >= 10) {
        printf ("\E[%d;%dH", 4, 20);
        printf("letter : %s\n", word);
        printf("\E[100;0HПРОИГРЫШ!\n");
        exit(0);
    }
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
            buf[k] = '\0';
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
void randWord(char** dictionary, char** word)
{
    int randW = rand() % SIZE;
    *word = dictionary[randW];
}
int searchLetter(char* word, char* tmp_word, char letter)
{
    int index = -1;
    for (size_t i = 0; i < strlen(word); i++) {
        if (word[i] == letter) {
            tmp_word[i] = letter;
            index = i;
        }
    }

    return index;
}
void helper()
{
    printf("-c - режим Страны\n-a - режим Животные\n-p - режим Растения\n");
}
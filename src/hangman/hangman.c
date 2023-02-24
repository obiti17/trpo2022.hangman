#include <libhangman.h>

int main(int argc, char** argv)
{
    char** dictionary = malloc(sizeof(char**));
    char* word = malloc(20);

    if (argc == 1) {
        fileRead(dictionary, 0);
    } else if (argc == 2) {
        if (!strcmp(argv[1], "--help")) {
            helper();
            exit(0);
        } else if (!strcmp(argv[1], "-c")) {
            fileRead(dictionary, 1);
        } else if (!strcmp(argv[1], "-a")) {
            fileRead(dictionary, 2);
        } else if (!strcmp(argv[1], "-p")) {
            fileRead(dictionary, 3);
        }
    } else if (argc > 2) {
        printf("Слишком много аргументов\n");
        helper();
        exit(0);
    }

    srand(time(NULL));
    randWord(dictionary, &word);

    printf("\E[H\E[J");

    char letter, *tmp_word = malloc(30);
    for (size_t i = 0; i < strlen(word); i++) {
        tmp_word[i] = '*';
    }
    tmp_word[strlen(word)] = '\0';

    int num_hang = 0;
    // printf("%s\n", word);
    while (strcmp(word, tmp_word)) {
        printf("\E[%d;%dH", 10, 0);
        printf("Enter letter : ");
        letter = getchar();
        if (letter == '\n')
            continue;
        printf("\E[H\E[J");
        if (searchLetter(word, tmp_word, letter) == -1) {
            num_hang++;
        }
        print(tmp_word, num_hang, word);
    }

    print(tmp_word, num_hang, word);
    printf("\E[%d;%dHВЫИГРАЛИ!\n", 100, 0);

    return 0;
}
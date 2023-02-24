#include "../libhangman/libhangman.h"

int main(int argc, char** argv)
{
    char** dictionary = malloc(sizeof(char**));
    char* word = malloc(20);
    char letter;

    if (argc == 1) {
        fileRead(dictionary, 0);
    } else if (argc == 2) {
        if (strcmp(argv[1], "--help")) {
            helper();
            exit(0);
        } else if (strcmp(argv[1], "-c")) {
            fileRead(dictionary, 1);
        } else if (strcmp(argv[1], "-a")) {
            fileRead(dictionary, 2);
        } else if (strcmp(argv[1], "-p")) {
            fileRead(dictionary, 3);
        }
    } else if (argc > 2) {
        printf("Слишком много аргументов\n");
        helper();
        exit(0);
    }

    randWord(dictionary, word);
    printf("%s\n", word);

    return 0;
}
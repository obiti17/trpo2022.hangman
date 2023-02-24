TARGET1 = ./bin/hangman
TARGET2 = ./obj/src/libhangman/libhangman.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
.PHONY : clean

$(TARGET1) : ./obj/src/hangman/hangman.o $(TARGET2)
	$(CC) $(CFLAGS) -o $@ ./obj/src/hangman/hangman.o -L./obj/src/libhangman -libhangman

$(TARGET2) : ./obj/src/libhangman/libhangman.o
	ar rcs $@ $^

./obj/src/libhangman/libhangman.o : ./src/libhangman/libhangman.c
	$(CC) -c $(CFLAGS) -o $@ $^

./obj/src/hangman/hangman.o : ./src/hangman/hangman.c
	$(CC) -c $(CFLAGS) -o $@ $^

run :
	./TARGET1

clean :
	rm ./obj/src/libhangman/libhangman.a ./obj/src/libhangman/libhangman.o ./obj/src/hangman/hangman.o ./bin/hangman
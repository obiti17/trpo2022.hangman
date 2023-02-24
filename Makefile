TARGET1 = ./bin/hangman
TARGET2 = ./obj/src/libhangman/libhangman.a
TARGET3 = ./bin/test
CC = gcc
CFLAGS = -Wall -Wextra -O0 -g -I ctest -I src/libhangman/
.PHONY : clean

$(TARGET1) : ./obj/src/hangman/hangman.o $(TARGET2) $(TARGET3)
	$(CC) $(CFLAGS) -o $@ ./obj/src/hangman/hangman.o -L./obj/src/libhangman -lhangman

$(TARGET2) : ./obj/src/libhangman/libhangman.o
	ar rcs $@ $^

$(TARGET3) : ./obj/test/main.o ./obj/test/test.o $(TARGET2)
	$(CC) $(CFLAGS) -o $@ ./obj/test/main.o ./obj/test/test.o -L./obj/src/libhangman -lhangman

./obj/test/main.o : ./test/main.c
	$(CC) -c $(CFLAGS) -o $@ $^

./obj/test/test.o : ./test/test.c
	$(CC) -c $(CFLAGS) -o $@ $^

./obj/src/libhangman/libhangman.o : ./src/libhangman/libhangman.c
	$(CC) -c $(CFLAGS) -o $@ $^

./obj/src/hangman/hangman.o : ./src/hangman/hangman.c
	$(CC) -c $(CFLAGS) -o $@ $^

run :
	./$(TARGET1)
run_test :
	./$(TARGET3)

clean :
	rm ./obj/src/libhangman/libhangman.a ./obj/src/libhangman/libhangman.o ./obj/src/hangman/hangman.o ./bin/hangman ./obj/test/main.o ./obj/test/test.o
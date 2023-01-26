CC=gcc

CFLAGS = -c -std=c++11
OBJ    = main.o assembler_functions.o
VPATH  = -I/CPU
--include-dir =CPU
all:     main

#include makefile

main:  $(OBJ)
	$(CC) -o main $(OBJ)

main.o: main.cpp assembler.h
assembler_functions.o: assembler_functions.cpp assembler.h

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./main

.PHONY : clean
clean:
	rm -rf *.o main

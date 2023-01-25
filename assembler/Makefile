CC=gcc

CFLAGS = -c
OBJ    = main.o assembler_functions.o
VPATH  = ../CPU
# --include-dir =CPU
all:     main

# include ../CPU/makefile

main:  $(OBJ)
	$(CC) -o main $(OBJ)

main.o: main.cpp assembler.h
assembler_functions.o: assembler_functions.cpp assembler.h



valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./main

.PHONY : clean
clean:
	rm -rf *.o main

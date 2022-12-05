include ../assembler/Makefile

CC=gcc

CFLAGS=-g
all: main

main: main.o
	$(CC) $(CFLAGS) main.cpp stack_check.cpp stack_functions.cpp processor_functions.cpp stack_dump.cpp -o main

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./main

clean:
	rm -rf *.o main


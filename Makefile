CC=gcc

CFLAGS=-g
all: main

main: main.o
	$(CC) $(CFLAGS) main.cpp stack_check.cpp stack_functions.cpp processor.cpp stack_dump.cpp assembler.cpp -o main

assembler: assembler.o
	$(CC) $(CFLAGS) assembler.cpp -o assembler

valgrind:
	valgrind ./main

clean:
	rm -rf *.o main


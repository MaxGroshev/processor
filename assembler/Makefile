CC=gcc

CFLAGS=-g
all: main

main: main.o
	$(CC) $(CFLAGS) main.cpp -o main

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./main

clean:
	rm -rf *.o main

CC=g++

CFLAGS = -c
OBJ    = main.o stack_check.o stack_functions.o processor_functions.o stack_dump.o
all: CPU

CPU: $(OBJ)
	$(CC) -o main $(OBJ)

main.o:                main.cpp CPU.h
stack_check.o:         stack_check.cpp CPU.h
stack_functions.o:     stack_functions.cpp CPU.h
processor_functions.o: processor_functions.cpp CPU.h


stack_dump.o: stack_dump.cpp int_stack.h
	$(CC) $(CFLAGS) stack_dump.cpp -lm

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./main

.PHONY : clean
clean:
	rm -rf *.o main


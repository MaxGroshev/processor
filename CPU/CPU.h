#include "int_stack.h"

struct processor
{
    int    registers[4]; //four registers ax, bx, cx, dx
    //struct stack_t box;
};

//------------------------------------------------------------------------------------------------------------------------------------------------

enum code_of_com
{
    HLT   = 0,
    PUSH  = 1,
    IN    = 2,
    ADD   = 3,
    MUL   = 4,
    OUT   = 5,
    DIV   = 6,
    SQRT  = 7,
    PUSHR = 11,
    POPR  = 12,
    JMP   = 20,  //jmp without condition
    JB    = 21,  // <
    JBE   = 22,  // <=
    JA    = 23,  // >
    JAE   = 24,  // >=
    JE    = 25,  // ==
    JNE   = 26,  // !=
    CALL  = 30,
    RET   = 31,
};

//--------------------------------------------------------------------------------------

void dist_task    (stack_t* box, stack_t* func_ret, processor* cpu, int elem);
int* read_num_com ();
void stack_add    (stack_t* box, int elem);
void stack_mul    (stack_t* box, int elem);
void stack_div    (stack_t* box, int elem);
void find_sqrt    (stack_t* box, int elem);

#include "int_stack.h"

struct processor
{
    //struct stack_t box;
    int registers[3]; //four registers ax, bx, cx, dx
};


enum code_of_com
{
    PUSH  = 1,
    PUSHR = 11,
    POPR  = 12,
    ADD   = 2,
    MUL   = 3,
    OUT   = 4,
    HLT   = 0,
};

//--------------------------------------------------------------------------------------

void processor   (stack_t* box, processor* cpu, int elem);
int* read_num_com ();
void stack_add    (stack_t* box, int elem);
void stack_mul    (stack_t* box, int elem);


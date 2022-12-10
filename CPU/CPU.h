#include "int_stack.h"

struct processor
{
    //struct stack_t box;
    int registers[4]; //four registers ax, bx, cx, dx
};

//------------------------------------------------------------------------------------------------------------------------------------------------

enum code_of_com
{
    PUSH  = 1,
    ADD   = 2,
    MUL   = 3,
    OUT   = 4,
    HLT   = 0,
    PUSHR = 11,
    POPR  = 12,
    JMP   = 20,
    CALL  = 30,
    RET   = 31,
};

//--------------------------------------------------------------------------------------

void dist_task (stack_t* box, stack_t* func_ret, processor* cpu, int elem);
int* read_num_com ();
void stack_add    (stack_t* box, int elem);
void stack_mul    (stack_t* box, int elem);


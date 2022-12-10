#include "int_stack.h"

struct processor
{
    //struct stack_t box;
    int registers[4]; //four registers ax, bx, cx, dx
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
    JMP   = 20,
    CALL  = 30,
    RET   = 31,
};

//--------------------------------------------------------------------------------------

void dist_task (stack_t* box, stack_t* func_ret, processor* cpu, int elem);
int* read_num_com ();
void stack_add    (stack_t* box, int elem);
void stack_mul    (stack_t* box, int elem);
void stack_div    (stack_t* box, int elem);
int  find_sqrt    (stack_t* box, int elem, int i);


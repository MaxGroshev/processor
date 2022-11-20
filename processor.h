#pragma once
#include "int_stack.h"

enum code_of_com
{
    PUSH = 1,
    ADD  = 2,
    MUL  = 3,
    OUT  = 4,
    HLT  = 5,
};

//--------------------------------------------------------------------------------------

void processor (stack_t* box, int elem);
void assembler ();
void stack_add (stack_t* box, int elem);
void stack_mul (stack_t* box, int elem);

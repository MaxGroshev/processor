#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_check.h"

//=================================================================================================================================

enum code_of_fails
{
    OUT_OF_STACK  = -3,
    WRONG_INPUT   = -2,
    ERR_NULL_DATA = -1,
    STACK_IS_OKEY =  0,
};

//---------------------------------------------------------------------------------------------------------------------------------

typedef int type_of_elem;

//--------------------------------------------------------------------------------

struct stack_t
{
    type_of_elem* data;
    size_t        counter;
    size_t        capacity;
};

//-----------------------------------------------------------------------------------------------------------------------------------

void stack_init    (stack_t* box);
void stack_push   (stack_t* box, type_of_elem element);
int  stack_pop    (stack_t* box);
int  stack_check  (stack_t* box);
void stack_delete (stack_t* box);
int  stack_dump   (stack_t* box, const char* DUR_FILE, const char* FUNCTION, int LINE, int print_stack);

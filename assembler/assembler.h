#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=================================================================================================================================

enum code_of_com
{
    PUSH = 1,
    ADD  = 2,
    MUL  = 3,
    OUT  = 4,
    HLT  = 5,
};

//==================================================================================================================================

struct token
{
    char* com;
    int   val;
};

//==================================================================================================================================

struct token* read_word_com (size_t* count_of_com, FILE* word_com);
void   translate_com (struct token* commands, const size_t count_of_com, FILE* word_com);

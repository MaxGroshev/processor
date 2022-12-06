#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token // token_t
{
    char* com;
    int   val;
};

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

char** read_word_com (size_t* count_of_com, size_t* count_of_token, FILE* word_com);
void   translate_com (struct token* commands, const size_t count_of_com, const size_t count_of_token, FILE* word_com);

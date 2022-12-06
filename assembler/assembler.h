
#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token // token_t
{
    char* com;
    char* val;
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

char* read_com_asm          (FILE* word_com);
struct token* read_word_com (size_t* count_of_com, size_t* count_of_token, char* test_text);
void translate_com          (struct token* commands, const size_t count_of_com, const size_t count_of_token, char* test_text);

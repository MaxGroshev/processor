
#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_err.h"

struct token // token_t
{
    char* com;
    char* val;
    int code_of_reg;
};

//=================================================================================================================================

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
};

enum registers
{
    ax = 0,
    bx = 1,
    cx = 2,
    dx = 3,
};

//==================================================================================================================================

char* read_com_asm          (FILE* word_com);
struct token* read_word_com (size_t* count_of_com, size_t* count_of_token, char* test_text);
void translate_com          (struct token* commands, const size_t count_of_com, const size_t count_of_token, char* test_text);

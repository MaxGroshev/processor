#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include "input_err.h"

struct stat;

//-------------------------------------------------------------------------------------------------------------------------------

struct token
{
    char*  com;
    char*  val;
    int    code_of_reg;
    char*  label;
};

//=================================================================================================================================

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
    POP   = 12,
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

enum registers
{
    ax = 100,
    bx = 101,
    cx = 102,
    dx = 103,
};

//==================================================================================================================================

char*  read_com_asm         (FILE* word_com);
struct token* read_word_com (size_t* count_of_com, size_t* count_of_token, int* labels, char* asm_text);
void   translate_com        (struct token* commands, const size_t count_of_com, const size_t count_of_token, int* labels, char* asm_text);
void   push_def             (struct token* commands, char* cur_tok, size_t* count_of_token, int i);

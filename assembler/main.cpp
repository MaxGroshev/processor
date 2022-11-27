#include "assembler.h"

struct token
{
    char* com;
    int   val;
    int   type;
};

int main ()
{
    FILE* word_com    = fopen ("../test.asm", "r");

    struct token* commands = read_word_com (word_com);
    //translate_com (word_com);

    fclose (word_com);
    free   (commands);
}

//----------------------------------------------------------------------------------------------------------------------------------------------



#include "assembler.h"

int main ()
{
    FILE* word_com    = fopen ("../test.asm", "r");
    size_t count_of_com = 0;

    struct token* commands = read_word_com (&count_of_com, word_com);
    translate_com (commands, count_of_com, word_com);

    fclose (word_com);
    free   (commands);
}

//----------------------------------------------------------------------------------------------------------------------------------------------



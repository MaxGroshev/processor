#include "assembler.h"

int main ()
{
    FILE* word_com    = fopen ("../test.asm", "r");

    size_t count_of_com = 0;   //count of commands that assembler will translate
    char** com_strings = read_word_com (&count_of_com, word_com);
    translate_com (com_strings, &count_of_com, word_com);

    fclose (word_com);


}

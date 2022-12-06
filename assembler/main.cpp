#include "assembler.h"

int main ()
{
    FILE* word_com    = fopen ("../test.asm", "r");
    size_t count_of_com =   0;
    size_t count_of_token = 0;

    char* test_text = read_com_asm (word_com);
    token* commands = read_word_com (&count_of_com, &count_of_token, test_text);
    translate_com (commands, count_of_com, count_of_token, test_text);

    fclose (word_com);
    free   (commands);
    free   (test_text);
}

#include "assembler.h"

int main ()
{
    FILE* word_com    = fopen ("../test.asm", "r");
    size_t count_of_com =   0;
    size_t count_of_token = 0;

    token* commands = read_word_com (&count_of_com, &count_of_token, word_com);
    for (int i = 0; i < count_of_com; i++)
    {
        printf("%s\n", commands[i].com);
    }
    int value = 0;

    printf("%d\n", value);


   // translate_com (commands, count_of_com, word_com);

    fclose (word_com);
    free   (commands);
}

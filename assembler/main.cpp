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

    int first_pos = ftell (word_com);
    fseek (word_com, 0, SEEK_END);
    int size_of_file = ftell (word_com);
    fseek (word_com, first_pos, SEEK_SET);
    printf ("%d\n", size_of_file);

    char* test_text = (char*) calloc (size_of_file, sizeof (char));
    fread (test_text, sizeof (char), size_of_file, word_com);

    struct token commands [100] = {};
    char* cur_tok = strtok (test_text, " \n");
    for (int i = 0; cur_tok; i++)
    {
        commands[i].com = cur_tok;
        cur_tok = strtok (NULL, " \n");
        printf("%s\n", commands[i].com);
    }

    //translate_com (com_strings, &count_of_com, word_com);

    fclose (word_com);
    free   (test_text);
}

//----------------------------------------------------------------------------------------------------------------------------------------------



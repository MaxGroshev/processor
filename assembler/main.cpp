#include "assembler.h"

int main ()
{
    FILE* word_com = fopen ("../fact.asm", "r");
    size_t count_of_com   = 0;
    size_t count_of_token = 0;
    int    labels[10] = {};
    memset (labels, -1, 10 * sizeof (int));

    char* test_text = read_com_asm (word_com);
    token* commands = read_word_com (&count_of_com, &count_of_token, labels, test_text);
    translate_com (commands, count_of_com, count_of_token, labels, test_text);

    fclose (word_com);
    free   (commands);
    free   (test_text);
}

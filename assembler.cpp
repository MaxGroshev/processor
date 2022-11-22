#include "processor.h"

void assembler()
{
    FILE* word_com = fopen ("test.asm", "r");
    FILE* num_com =  fopen ("test.code","a");

    size_t count_of_strings = 5;    //count of strings to which memory will be allocated
    int symb_in_com [10];           //count of symbols in each command (use to request memory)
    char** com_strings = (char**) calloc (count_of_strings, sizeof (char*)); //array of pointers to commands
    size_t count_of_com = 0;        //count of commands that assembler will translate
    while(!feof (word_com))
    {
        if (count_of_com >= count_of_strings)
        {
            count_of_strings += 10;
            char** com_strings_resize = com_strings;
            com_strings_resize = (char**) realloc (com_strings, (count_of_strings) * sizeof (char*));
            if (com_strings_resize != NULL)
            {
                com_strings = com_strings_resize;
            }
            else
            {
                printf ("Count of comands is to much\n");
            }
        }
        size_t len = 5;

        symb_in_com [count_of_com] = getline (&com_strings [count_of_com], &len, word_com);
        count_of_com++;
    }
    count_of_com--;

    for (int i = 0; i < count_of_com; i++)
    {
        char* command = (char*) calloc (symb_in_com[i] - 1, sizeof (char));
        int value = 0;
        sscanf (com_strings [i], "%s %d", command, &value);

        if (strcmp (command, "push") == 0)
        {
            fscanf (word_com,"%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);
            free (command);
            continue;
        }

        else if (strcmp (command, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            free (command);
            continue;
        }

        else if (strcmp (command, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            free (command);
            continue;
        }

        else if (strcmp (command, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            free (command);
            continue;
        }

        else if (strcmp (command, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            free (command);
        }
    }
    fprintf(num_com, "------End of list of commands------\n");
    fclose (word_com);
    fclose (num_com);
    free   (com_strings);
}

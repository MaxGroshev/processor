#include "assembler.h"

char** read_word_com (size_t* count_of_com, FILE* word_com)
{
    size_t count_of_strings = 10;                                            //count of strings to which memory will be allocated //fault is here
    char** com_strings = (char**) calloc (count_of_strings, sizeof (char*)); //array of pointers to commands
    while (!feof (word_com))
    {
        if (*count_of_com >= count_of_strings)
        {
            count_of_strings += 10;
            char** com_strings_resize = com_strings;
            com_strings_resize = (char**)  realloc (com_strings, (count_of_strings) * sizeof (char*));
            if (com_strings_resize != NULL)
            {
                com_strings = com_strings_resize;
            }
            else
            {
                printf ("Error of reallocating\n");
            }
        }
        size_t len = 6;

        getline (&com_strings [*count_of_com], &len, word_com);
        (*count_of_com)++;

    }
    (*count_of_com)--;
    return com_strings;
}

//-----------------------------------------------------------------------------------------------------------------------------

void translate_com (char** com_strings, size_t* count_of_com, FILE* word_com)
{
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");

    int cmd_array[*count_of_com * 2];
    int count_of_cmd_com = 0;
    for (int i = 0; i < *count_of_com; i++)
    {
        char* command = (char*) calloc (7, sizeof (char));
        int value = 0;
        sscanf (com_strings [i], "%s %d", command, &value);

        if (strcmp (command, "push") == 0)
        {
            fscanf  (word_com,"%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);
            cmd_array[count_of_cmd_com++] = PUSH;
            cmd_array[count_of_cmd_com++] = value;
            free (command);
            continue;
        }

        else if (strcmp (command, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[count_of_cmd_com++] = ADD;
            free (command);
            continue;
        }

        else if (strcmp (command, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[count_of_cmd_com++] = MUL;
            free (command);
            continue;
        }

        else if (strcmp (command, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[count_of_cmd_com++] = OUT;
            free (command);
            continue;
        }

        else if (strcmp (command, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[count_of_cmd_com++] = HLT;
            free (command);
            continue;
        }

        else if (strcmp (command, "\n") == 0)
        {
            fprintf (num_com, "\n");
            free (command);
        }
    }
    fprintf(num_com, "------End of list of commands------\n");
    fwrite (cmd_array, sizeof (int), count_of_cmd_com , num_com_bin);
    fclose (num_com);
    free   (com_strings);
}

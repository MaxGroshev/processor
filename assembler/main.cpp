#include "assembler.h"
char** read_word_com (size_t* count_of_com, FILE* word_com);

int main ()
{
    FILE* word_com    = fopen ("../test.asm", "r");
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");
    size_t count_of_com = 0 ;   //count of commands that assembler will translate
    char** com_strings = read_word_com (&count_of_com, word_com);
    int cmd_array[100];
    int j = 0;
    for (int i = 0; i < count_of_com; i++)
    {
        char* command = (char*) calloc (7, sizeof (char));
        int value = 0;
        sscanf (com_strings [i], "%s %d", command, &value);

        if (strcmp (command, "push") == 0)
        {
            fscanf  (word_com,"%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);
            cmd_array[j] = PUSH;
            j++;
            cmd_array[j] = value;
            j++;
            //fwrite (cmd, sizeof (value), 1, num_com_bin);
            free (command);
            continue;
        }

        else if (strcmp (command, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[j] = ADD;
            j++;
            free (command);
            continue;
        }

        else if (strcmp (command, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[j] = MUL;
            j++;
            free (command);
            continue;
        }

        else if (strcmp (command, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[j] = OUT;
            j++;
            free (command);
            continue;
        }

        else if (strcmp (command, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[j] = HLT;
            j++;
            free (command);
            continue;
        }

        else if (strcmp (command, "\n") == 0)
        {
            fprintf (num_com, "\n");
            free (command);
        }
    }
   // fprintf(num_com, "------End of list of commands------\n");
    fwrite (cmd_array, sizeof (int), j , num_com_bin);
    fclose (word_com);
    fclose (num_com);
    free   (com_strings);
}

//----------------------------------------------------------------------------------------------------------------------------------------------

char** read_word_com (size_t* count_of_com, FILE* word_com)
{
    size_t count_of_strings = 10;    //count of strings to which memory will be allocated //fault is here
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
      for (int i = 0; i < *count_of_com; i++)
        {
            printf ("%s", com_strings[i]);
        }
    return com_strings;
}

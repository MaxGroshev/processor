#include "test.h"

void assembler()
{
    FILE* word_com = fopen ("test.asm", "r");
    FILE* num_com =  fopen ("test.code","a");
    char* command = (char*) calloc (100, sizeof (char));
    for (int i = 0;; i++)
    {
        char c = '\0';
        int num_of_sym = 0;
        while (c = fgetc (word_com))
        {
            if (c == '\n' || c == 32)
            {
                break;
            }
            command [num_of_sym] = c;
            num_of_sym++;
        }

        if (strcmp (command, "push") == 0)
        {
            int value = 0;
            fscanf (word_com,"%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);
            continue;
        }

        command [num_of_sym - 1] = '\0';
        if (strcmp (command, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            continue;
        }

        else if (strcmp (command, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            continue;
        }

        else if (strcmp (command, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            continue;
        }

        else if (strcmp (command, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            free (command);
            break;
        }

    }
    fprintf (num_com, "------End of list of commands------\n");
    fclose (word_com);
    fclose (num_com);

}

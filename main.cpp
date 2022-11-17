#include "test.h"

int main()
{
    FILE* word_com = fopen ("test.asm", "r");
    FILE* num_com =  fopen ("test.code","a");
    char* command = (char*) calloc (100, sizeof(char));;
    for (int i = 0;; i++)
    {
        char c = 'i';

        int j = 0;
        while(c = fgetc(word_com))
        {

            if (c == '\n' || c == 32)
            {
                break;
            }
            command [j] = c;
            printf("%c\n", c);
            j++;
        }

        if (strcmp (command, "push") == 0)
        {
            int value = 0;
            fscanf(word_com,"%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);
            printf("%d\n", value);
            continue;
        }

        command[j - 1] = '\0';
        if (strcmp (command, "add") == 0)
        {
            printf("%s\n", command);
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
            fprintf (num_com, "%d\n", OUT);//pop + print
            continue;
        }

        else if (strcmp (command, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);// exit
            free(command);
            fprintf (num_com, "------End of list of commands------\n");
            break;
        }

    }
    fclose (word_com);
    fclose (num_com);
}

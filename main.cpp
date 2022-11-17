#include "test.h"

int main()
{
    FILE* word_com = fopen ("test.asm", "r");
    FILE* num_com =  fopen ("test.code","a");
    char* command = NULL;
    for (int i = 0;; i++)
    {
        command  = (char*) calloc (15, sizeof(char));
        //printf("%s\n", command);
        char c = 'o';
        int j = 0;
        while(c != '\n')
        {
            c = fgetc(word_com);
            command [j] = c;
            printf("%c\n", c);
            j++;

            if (strcmp (command, "push") == 0)
            {
                //printf("Hello\n");
                int value = 0;
                fscanf(word_com,"%d", &value);
                fprintf (num_com, "%d %d\n", PUSH, value);
                printf("%d\n", value);
                break;
            }

            //command[j - 1] = '\0';
            if (strcmp (command, "add") == 0)
            {
                printf("%s\n", command);
                fprintf (num_com, "%d\n", ADD);
                break;
            }

            else if (strcmp (command, "mul") == 0)
            {
                fprintf (num_com, "%d\n", MUL);
                break;
            }

            else if (strcmp (command, "out") == 0)
            {
                fprintf (num_com, "%d\n", OUT);//pop + print
                break;
            }

            else if (strcmp (command, "hlt") == 0)
            {
                printf("HTL\n");
                fprintf (num_com, "%d\n", HLT);// exit
                //free(command);
                break;
            }
        }
        if (strcmp (command, "hlt") == 0)
        {
            //printf("HTL\n");
            //fprintf (num_com, "%d\n", HLT);// exit
            //free(command);

            free(command);
            break;
        }
        free(command);
    }
    fclose (word_com);
    fclose (num_com);
}

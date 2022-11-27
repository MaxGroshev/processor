#include "assembler.h"

struct token* read_word_com (size_t* count_of_com, FILE* word_com)
{
    size_t token_mem = 10;
    struct token* commands = (struct token*) calloc (token_mem, sizeof (struct token));
    for (int i = 0; !feof (word_com); i++)
    {
        if (token_mem - 2 <= i)
        {
            token_mem += 10;
            struct token* commands_resize = commands;
            commands_resize = (struct token*) realloc (commands, token_mem * sizeof (struct token));

            if (commands_resize != NULL)
            {
                commands = commands_resize;
            }

            else
            {
                printf ("Eroor of reallocating\n");
            }
        }

        char* str = (char*) calloc (10, sizeof (char));
        char* str_copy;
        int value = 0;
        int ret_val = fscanf (word_com, "%s %d", str_copy, &value);

        if (((strcmp (str_copy, "push") != 0) && (ret_val != 1)) || ((strcmp (str_copy, "push") == 0) && (ret_val != 2)))
        {
            fprintf (stderr, "Wrong input of commands. Check ""test.asm"" and repeat again\n");
            exit(1);
        }

        else
        {
            commands[i].com = str_copy;
            if (strcmp (str_copy, "push") == 0)
            {
                commands[i].val = value;
                (*count_of_com)++;
            }
        }
        free (str_copy);
        printf("%s\n", commands[i].com);
        (*count_of_com)++;
    }

    printf ("%ld\n", *count_of_com);
    return commands;
}

//-----------------------------------------------------------------------------------------------------------------------------

void translate_com (struct token* commands, const size_t count_of_com, FILE* word_com)
{
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");

    int cmd_array[count_of_com];
    for (int i = 0; i < count_of_com; i++)
    {
        int value = 0;

        if (strcmp (commands[i].com, "push") == 0)
        {

            fprintf (num_com, "%d %d\n", PUSH, commands[i].val);
            cmd_array[i++] = PUSH;
            cmd_array[i++] = commands[i].val;
            continue;
        }

        else if (strcmp (commands[i].com, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[i] = ADD;
            continue;
        }

        else if (strcmp (commands[i].com, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[i] = MUL;
            continue;
        }

        else if (strcmp (commands[i].com, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[i] = OUT;
            continue;
        }

        else if (strcmp (commands[i].com, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[i] = HLT;
            continue;
        }

        else if (strcmp (commands[i].com, "\n") == 0)
        {
            fprintf (num_com, "\n");
        }
    }
    fprintf(num_com, "------End of list of commands------\n");
    fwrite (cmd_array, sizeof (int), count_of_com , num_com_bin);
    fclose (num_com);
}


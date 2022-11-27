#include "assembler.h"

struct token
{
    char* com;
    int   val;
    int   type;
};

struct token* read_word_com (size_t* count_of_com, FILE* word_com)
{

    int first_pos = ftell (word_com);
    fseek (word_com, 0, SEEK_END);
    int size_of_file = ftell (word_com);
    fseek (word_com, first_pos, SEEK_SET);
    printf ("%d\n", size_of_file);

    char* test_text = (char*) calloc (size_of_file, sizeof (char));
    fread (test_text, sizeof (char), size_of_file, word_com);

    size_t token_mem = 10;
    struct token* commands =(struct token*) calloc (token_mem, sizeof (struct token));
    char* cur_tok = strtok (test_text, " \n");
    commands[0].com = cur_tok;
    for (int i = 1; i < 12; i++) // proplem in last symbol
    {
        if (token_mem <= i)
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
        commands[i].com = cur_tok;
        (*count_of_com) ++;
        cur_tok = strtok (NULL, " \n");

        printf("%s\n", commands[i].com);
    }
    printf ("%ld\n", *count_of_com);
    printf("%s\n", commands[0].com);
    free (test_text);
    return commands;
}

//-----------------------------------------------------------------------------------------------------------------------------

void translate_com (struct token* commands, const size_t count_of_com, FILE* word_com)
{
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");

    int cmd_array[100];
    int i = 0;
    for (; i < count_of_com; i++)
    {
        char* str = (char*) calloc (7, sizeof (char));
        int value = 0;

        if (strcmp (commands[i].com, "push") == 0)
        {
            sscanf (commands[i].com, "%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);
            cmd_array[i++] = PUSH;
            cmd_array[i++] = value;
            free (str);
            continue;
        }

        else if (strcmp (commands[i].com, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[i++] = ADD;
            free (str);
            continue;
        }

        else if (strcmp (commands[i].com, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[i++] = MUL;
            free (str);
            continue;
        }

        else if (strcmp (commands[i].com, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[i++] = OUT;
            free (str);
            continue;
        }

        else if (strcmp (commands[i].com, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[i++] = HLT;
            free (str);
            continue;
        }

        else if (strcmp (commands[i].com, "\n") == 0)
        {
            fprintf (num_com, "\n");
            free (str);
        }
    }
    fprintf(num_com, "------End of list of commands------\n");
    fwrite (cmd_array, sizeof (int), i , num_com_bin);
    fclose (num_com);
}


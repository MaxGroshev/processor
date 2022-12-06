#include "assembler.h"

char* read_com_asm (FILE* word_com)
{
    int first_pos = ftell (word_com);
    fseek (word_com, 0, SEEK_END);
    int size_of_file = ftell (word_com);
    fseek (word_com, first_pos, SEEK_SET);

    char* test_text = (char*) calloc (size_of_file + 5, sizeof (char));
    fread (test_text, sizeof (char), size_of_file, word_com);
    for (int i = 0; i < size_of_file; i++)
    {
        if (test_text[i] == 13)
        {
            test_text[i] = '\r';
        }
    }
    return test_text;
}

struct token* read_word_co m (size_t* count_of_com, size_t* count_of_token, char* test_text)
{

    size_t token_mem = 10;
    struct token* commands = (struct token*) calloc (token_mem, sizeof (struct token));
    char* cur_tok = strtok (test_text, " \r\n");
    commands[0].com = cur_tok;
    for (int i = 1; cur_tok != NULL; i++)
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
                printf ("Error of reallocating\n");
            }
        }

        if (strcmp (commands[i - 1].com, "push") == 0)
        {
            cur_tok = strtok (NULL, " \r\n");
            commands[i - 1].val = cur_tok;
            (*count_of_token)++;
        }

        cur_tok = strtok (NULL, " \r\n");
        if (cur_tok != NULL)
        {
            commands[i].com = cur_tok;
        }

        else
        {
            break;
        }
        (*count_of_com)++;
        (*count_of_token)++;
    }
    (*count_of_com)++;
    (*count_of_token)++;
    return commands;
}

//-----------------------------------------------------------------------------------------------------------------------------

void translate_com (struct token* commands, const size_t count_of_com, const size_t count_of_token, char* test_text)
{
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");

    int cmd_array[count_of_token];
    int j = 0;
    for (int i = 0; i < count_of_com && j < count_of_token; i++, j++)
    {
        int value = 0;
        if (strcmp (commands[i].com, "push") == 0)
        {
            sscanf (commands[i].val, "%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);

            cmd_array[j] = PUSH;
            j++;
            cmd_array[j] = value;
            continue;
        }

        else if (strcmp (commands[i].com, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[j] = ADD;
            continue;
        }

        else if (strcmp (commands[i].com, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[j] = MUL;
            continue;
        }

        else if (strcmp (commands[i].com, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[j] = OUT;
            continue;
        }

        else if (strcmp (commands[i].com, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[j] = HLT;
            continue;
        }

        else if (strcmp (commands[i].com, "\n") == 0)
        {
            fprintf (num_com, "\n");
        }
    }
    fprintf(num_com, "------End of list of commands------\n");
    fwrite (cmd_array, sizeof (int), count_of_token , num_com_bin);
    fclose (num_com);
    fclose (num_com_bin);
}

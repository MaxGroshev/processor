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

struct token* read_word_com (size_t* count_of_com, size_t* count_of_token, int* labels, char* test_text)
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

        else if ((strcmp (commands[i - 1].com, "pushr") == 0) || (strcmp (commands[i - 1].com, "popr") == 0))
        {
            cur_tok = strtok (NULL, " \r\n");

            if      (strcmp (cur_tok, "ax") == 0) commands[i - 1].code_of_reg = ax;
            else if (strcmp (cur_tok, "bx") == 0) commands[i - 1].code_of_reg = bx;
            else if (strcmp (cur_tok, "cx") == 0) commands[i - 1].code_of_reg = cx;
            else if (strcmp (cur_tok, "dx") == 0) commands[i - 1].code_of_reg = dx;

            (*count_of_token)++;
        }

        else if ((strcmp (commands[i - 1].com, "jmp") == 0) || (strcmp (commands[i - 1].com, "call") == 0))
        {
            cur_tok = strtok (NULL, " \r\n");
            commands[i - 1].label = cur_tok;
            (*count_of_token)++;
        }

        if ((strchr (cur_tok, ':') != NULL) && (strcmp (commands[i - 1].com, "jmp") != 0) && (strcmp (commands[i - 1].com, "call") != 0))
        {
            printf ("Buy\n");
            int num_of_label = 0;
            int res = sscanf (cur_tok, ":%d", &num_of_label);
            labels[num_of_label] = *count_of_token;
            (*count_of_token)--;
        }

        cur_tok = strtok (NULL, " \r\n");
        if (cur_tok != NULL)
        {
            commands[i].com = cur_tok;
            (*count_of_com)++;
            (*count_of_token)++;
        }

        else
        {
            break;
        }
    }
    (*count_of_com)++;
    (*count_of_token)++;
    printf ("%ld\n", *count_of_token);
    return commands;
}

//-----------------------------------------------------------------------------------------------------------------------------

void translate_com (struct token* commands, const size_t count_of_com, const size_t count_of_token, int* labels, char* test_text)
{
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");

    int cmd_array[count_of_token];
    int j = 0;
    for (int i = 0; i < count_of_com && j < count_of_token; i++, j++)
    {
        int value = 0;
        int code_of_reg = -1;
        if (strcmp (commands[i].com, "push") == 0)
        {
            if (sscanf (commands[i].val, "%d", &value) == 1)
            {
                fprintf (num_com, "%d %d\n", PUSH, value);

                cmd_array[j] = PUSH;
                j++;
                cmd_array[j] = value;
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "pushr") == 0)
        {
            if (commands[i].code_of_reg >= ax && commands[i].code_of_reg <= dx)
            {
                fprintf (num_com, "%d %d\n", PUSHR, commands[i].code_of_reg);
                cmd_array[j] = PUSHR;
                j++;
                cmd_array[j] = commands[i].code_of_reg;
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "popr") == 0)
        {
            if (commands[i].code_of_reg >= ax && commands[i].code_of_reg <= dx)
            {
                fprintf (num_com, "%d %d\n", POPR, commands[i].code_of_reg);
                cmd_array[j] = POPR;
                j++;
                cmd_array[j] = commands[i].code_of_reg;
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "jmp") == 0)
        {
            int num_of_label = 0;
            if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
            {
                fprintf (num_com, "%d %d\n", JMP, labels[num_of_label]);
                cmd_array[j] = JMP;
                j++;
                cmd_array[j] = labels[num_of_label];
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "call") == 0)
        {
            int num_of_label = 0;
            if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
            {
                fprintf (num_com, "%d %d\n", CALL, labels[num_of_label]);
                cmd_array[j] = CALL;
                j++;
                cmd_array[j] = labels[num_of_label];
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "ret") == 0)
        {
            fprintf (num_com, "%d\n", RET);
            cmd_array[j] = RET;
        }

        else if (strcmp (commands[i].com, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[j] = ADD;
        }

        else if (strcmp (commands[i].com, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[j] = MUL;
        }

        else if (strcmp (commands[i].com, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[j] = OUT;
        }

        else if (strcmp (commands[i].com, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[j] = HLT;
        }

        else if (strcmp (commands[i].com, "\n") == 0)
        {
            fprintf (num_com, "\n");
        }

        else if (strchr (commands[i].com, ':') != NULL)
        {
            j--;
            continue;
        }
        else INPUT_ERR
    }

    fprintf(num_com, "------End of list of commands------\n");
    fwrite (cmd_array, sizeof (int), j , num_com_bin); // to improve j
    fclose (num_com);
    fclose (num_com_bin);
}

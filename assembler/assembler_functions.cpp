#include "assembler.h"

char* read_com_asm (FILE* word_com)
{
    struct stat stat_of_txt = {};
    stat   ("../fact.asm", &stat_of_txt);
    size_t size_of_file = stat_of_txt.st_size;

    char*  asm_text = (char*) calloc (size_of_file + 1, sizeof (char));
    fread  (asm_text, sizeof (char), size_of_file, word_com);
    return asm_text;
}

struct token* read_word_com (size_t* count_of_com, size_t* count_of_token, int* labels, char* asm_text)
{
    size_t token_mem = 10;
    struct token* commands = (struct token*) calloc (token_mem, sizeof (struct token));
    char*  cur_tok = strtok (asm_text, " \r\n\t");
    commands[0].com = cur_tok;
    for (int i = 1; cur_tok != NULL; i++)
    {
        if (token_mem <= i)
        {
            token_mem *= 2;
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

        if ((strcmp (commands[i - 1].com, "push") == 0) || (strcmp (commands[i - 1].com, "pop") == 0))
        {
            push_def (commands, cur_tok, count_of_token, i);
        }

        else if ((strchr (commands[i - 1].com, 'j') != NULL) || (strcmp (commands[i - 1].com, "call") == 0))
        {
            cur_tok = strtok (NULL, " \r\n\t");
            commands[i - 1].label = cur_tok;
            (*count_of_token)++;
        }

        if ((strchr (cur_tok, ':') != NULL) && (strchr (commands[i - 1].com, 'j') == NULL) && (strcmp (commands[i - 1].com, "call") != 0))
        {
            int num_of_label = 0;
            int res = sscanf (cur_tok, ":%d", &num_of_label);
            labels[num_of_label] = *count_of_token;
            (*count_of_token)--;
        }

        cur_tok = strtok (NULL, " \r\n\t");
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

void push_def (struct token* commands, char* cur_tok, size_t* count_of_token, int i)
{
    cur_tok = strtok (NULL, " \r\n\t");
    if (strchr (cur_tok, 'x') != NULL)
    {
        if      (strcmp (cur_tok, "ax") == 0) commands[i - 1].code_of_reg = ax;
        else if (strcmp (cur_tok, "bx") == 0) commands[i - 1].code_of_reg = bx;
        else if (strcmp (cur_tok, "cx") == 0) commands[i - 1].code_of_reg = cx;
        else if (strcmp (cur_tok, "dx") == 0) commands[i - 1].code_of_reg = dx;
        //else    INPUT_ERR //not a loop

        if (strcmp (commands[i - 1].com, "push") == 0)
        {
            commands[i - 1].com = (char*) "pushr";
        }
    }

    else
    {
        commands[i - 1].val = cur_tok;
    }

    //else INPUT_ERR
    (*count_of_token)++;
}

//-----------------------------------------------------------------------------------------------------------------------------

void translate_com (struct token* commands, const size_t count_of_com, const size_t count_of_token, int* labels, char* asm_text)
{
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");

    int cmd_array[count_of_token];
    int cmd_size = 0;
    for (int i = 0; i < count_of_com && cmd_size < count_of_token; i++, cmd_size++)
    {
        int value = 0;
        int code_of_reg = -1;
        if (strcmp (commands[i].com, "push") == 0)
        {
            if (sscanf (commands[i].val, "%d", &value) == 1)
            {
                fprintf (num_com, "%d %d\n", PUSH, value);

                cmd_array[cmd_size] = PUSH;
                cmd_size++;
                cmd_array[cmd_size] = value;
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "in") == 0)
        {
            fprintf (num_com, "%d\n", IN);
            cmd_array[cmd_size] = IN;
        }

        else if (strcmp (commands[i].com, "pushr") == 0)
        {
            if (commands[i].code_of_reg >= ax && commands[i].code_of_reg <= dx)
            {
                fprintf (num_com, "%d %d\n", PUSHR, commands[i].code_of_reg);
                cmd_array[cmd_size] = PUSHR;
                cmd_size++;
                cmd_array[cmd_size] = commands[i].code_of_reg;
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "pop") == 0) // not finished ver: work in case of registers
        {
            if (commands[i].code_of_reg >= ax && commands[i].code_of_reg <= dx)
            {
                fprintf (num_com, "%d %d\n", POP, commands[i].code_of_reg);
                cmd_array[cmd_size] = POP;
                cmd_size++;
                cmd_array[cmd_size] = commands[i].code_of_reg;
            }
            else INPUT_ERR
        }

        else if (strchr (commands[i].com, 'j') != NULL) // make function
        {
            int num_of_label = 0;
            if (strcmp (commands[i].com, "jmp") == 0)
            {
                if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
                {
                    fprintf (num_com, "%d %d\n", JMP, labels[num_of_label]);
                    cmd_array[cmd_size] = JMP;
                    cmd_size++;
                    cmd_array[cmd_size] = labels[num_of_label];
                }
                else INPUT_ERR
            }

            else if (strcmp (commands[i].com, "jb") == 0)
            {
                if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
                {
                    fprintf (num_com, "%d %d\n", JB, labels[num_of_label]);
                    cmd_array[cmd_size] = JB;
                    cmd_size++;
                    cmd_array[cmd_size] = labels[num_of_label];
                }
                else INPUT_ERR
            }

            else if (strcmp (commands[i].com, "jbe") == 0)
            {
                if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
                {
                    fprintf (num_com, "%d %d\n", JBE, labels[num_of_label]);
                    cmd_array[cmd_size] = JBE;
                    cmd_size++;
                    cmd_array[cmd_size] = labels[num_of_label];
                }
                else INPUT_ERR
            }

            else if (strcmp (commands[i].com, "ja") == 0)
            {
                if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
                {
                    fprintf (num_com, "%d %d\n", JA, labels[num_of_label]);
                    cmd_array[cmd_size] = JA;
                    cmd_size++;
                    cmd_array[cmd_size] = labels[num_of_label];
                }
                else INPUT_ERR
            }

            else if (strcmp (commands[i].com, "jae") == 0)
            {
                if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
                {
                    fprintf (num_com, "%d %d\n", JAE, labels[num_of_label]);
                    cmd_array[cmd_size] = JAE;
                    cmd_size++;
                    cmd_array[cmd_size] = labels[num_of_label];
                }
                else INPUT_ERR
            }

            else if (strcmp (commands[i].com, "je") == 0)
            {
                if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
                {
                    fprintf (num_com, "%d %d\n", JE, labels[num_of_label]);
                    cmd_array[cmd_size] = JE;
                    cmd_size++;
                    cmd_array[cmd_size] = labels[num_of_label];
                }
                else INPUT_ERR
            }

            else if (strcmp (commands[i].com, "jne") == 0)
            {
                if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
                {
                    fprintf (num_com, "%d %d\n", JNE, labels[num_of_label]);
                    cmd_array[cmd_size] = JNE;
                    cmd_size++;
                    cmd_array[cmd_size] = labels[num_of_label];
                }
                else INPUT_ERR
            }
        }

        else if (strcmp (commands[i].com, "call") == 0)
        {
            int num_of_label = 0;
            if (sscanf (commands[i].label, ":%d", &num_of_label) == 1)
            {
                fprintf (num_com, "%d %d\n", CALL, labels[num_of_label]);
                cmd_array[cmd_size] = CALL;
                cmd_size++;
                cmd_array[cmd_size] = labels[num_of_label];
            }
            else INPUT_ERR
        }

        else if (strcmp (commands[i].com, "ret") == 0)
        {
            fprintf (num_com, "%d\n", RET);
            cmd_array[cmd_size] = RET;
        }

        else if (strcmp (commands[i].com, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[cmd_size] = ADD;
        }

        else if (strcmp (commands[i].com, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[cmd_size] = MUL;
        }

        else if (strcmp (commands[i].com, "div") == 0)
        {
            fprintf (num_com, "%d\n", DIV);
            cmd_array[cmd_size] = DIV;
        }

        else if (strcmp (commands[i].com, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[cmd_size] = OUT;
        }

        else if (strcmp (commands[i].com, "sqrt") == 0)
        {
            fprintf (num_com, "%d\n", SQRT);
            cmd_array[cmd_size] = SQRT;
        }

        else if (strcmp (commands[i].com, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[cmd_size] = HLT;
        }

        else if (strcmp (commands[i].com, "\n") == 0)
        {
            fprintf (num_com, "\n");
        }

        else if (strchr (commands[i].com, ':') != NULL)
        {
            cmd_size--;
            continue;
        }
        else INPUT_ERR
    }

    fprintf(num_com, "------End of list of commands------\n");
    fwrite (cmd_array, sizeof (int), cmd_size , num_com_bin);
    fclose (num_com);
    fclose (num_com_bin);
}
// make define with names of commands or array with name

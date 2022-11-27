#include "assembler.h"

struct token
{
    char* com;
    int   val;
    int   type;
};

/*struct* read_word_com (size_t* count_of_com, FILE* word_com)
{

    int first_pos = ftell (word_com);
    fseek (word_com, 0, SEEK_END);
    int size_of_file = ftell (word_com);
    fseek (word_com, first_pos, SEEK_SET);
    printf ("%d\n", size_of_file);

    char* test_text = (char*) calloc (size_of_file, sizeof (int));
    fread (test_text, sizeof (char), size_of_file, word_com);
    //return com_strings;


    struct commands [100] = {};
    char* cur_tok = strtok (com_strings, " \n");
    //char* cur_tok;
    for (int i = 0; cur_tok; i++)
    {
        commands[i].com = cur_tok;
        cur_tok = strtok (NULL, " \n");
        printf("%s\n", commands[i].com);
    }
    return commands

}*/

//-----------------------------------------------------------------------------------------------------------------------------

/*void translate_com (char* com_strings, size_t* count_of_com, FILE* word_com)
{
    FILE* num_com     = fopen ("../test.code","w");
    FILE* num_com_bin = fopen ("../test-code.bin","wb");

    int cmd_array[100];
    int j = 0;
    for (int i = 0; i < *count_of_com; i++)
    {
        char* command = (char*) calloc (7, sizeof (char));
        int value = 0;
        sscanf (com_strings, "%s %d", command, &value);

        if (strcmp (command, "push") == 0)
        {
            fscanf  (word_com,"%d", &value);
            fprintf (num_com, "%d %d\n", PUSH, value);
            cmd_array[j++] = PUSH;
            cmd_array[j++] = value;
            free (command);
            continue;
        }

        else if (strcmp (command, "add") == 0)
        {
            fprintf (num_com, "%d\n", ADD);
            cmd_array[j++] = ADD;
            free (command);
            continue;
        }

        else if (strcmp (command, "mul") == 0)
        {
            fprintf (num_com, "%d\n", MUL);
            cmd_array[j++] = MUL;
            free (command);
            continue;
        }

        else if (strcmp (command, "out") == 0)
        {
            fprintf (num_com, "%d\n", OUT);
            cmd_array[j++] = OUT;
            free (command);
            continue;
        }

        else if (strcmp (command, "hlt") == 0)
        {
            fprintf (num_com, "%d\n", HLT);
            cmd_array[j++] = HLT;
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
    fwrite (cmd_array, sizeof (int), j , num_com_bin);
    fclose (num_com);
}


    //count of strings to which memory will be allocated //fault is here

/*int count_of_strings = 5;
    char** com_strings = (char**) calloc (count_of_strings, sizeof (char) * 10); //array of pointers to commands
    while (!feof (word_com))
    {
        if (*count_of_com >= count_of_strings)
        {
            count_of_strings += 10;
            char** com_strings_resize = com_strings;
            com_strings_resize = (char**)  realloc (com_strings, (count_of_strings) * sizeof (char)*10);
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
    return com_strings;*/

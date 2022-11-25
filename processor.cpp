#include "processor.h"

void processor (stack_t* box, int elem)
{
    int* code_of_com = read_num_com();

    for (int i = 0; code_of_com[i] != HLT; i++)
    {
        switch (code_of_com[i])
        {
            case PUSH:
                i++;
                elem = code_of_com[i];
                stack_push (box, elem);
                break;

            case ADD:
                stack_add (box, elem);
                break;

            case MUL:
                stack_mul (box, elem);
                break;

            case OUT:
                elem = stack_pop (box);
                printf ("%d\n", elem);
                break;

            case HLT:
                break;
        }
    }
    free (code_of_com);
}

//------------------------------------------------------------------------------------------------------------------------------------------------

int* read_num_com ()
{
    int size_of_com = 5;
    int* code_of_com = (int*) calloc (size_of_com, sizeof (int));
    FILE* num_com = fopen ("test.code", "r");
    for (int i = 0;; i++)
    {
        if (size_of_com <= i)
        {
            size_of_com += 10;
            int* code_of_com_resize = code_of_com;
            code_of_com_resize = (int*) realloc (code_of_com, size_of_com * sizeof (int));

            if (code_of_com_resize != NULL)
            {
                code_of_com = code_of_com_resize;
            }

            else
            {
                printf ("Eroor of reallocating\n");
            }
        }

        int buffer = 0;
        fscanf (num_com,"%d", &buffer);

        if (feof (num_com))
        {
            break;
        }
        code_of_com[i] = buffer;
    }
    fclose (num_com);
    return code_of_com;
}


void stack_add (stack_t* box, int elem)
{
    elem = stack_pop  (box);
    elem += stack_pop (box);
    stack_push (box, elem);
    STACK_CHECK
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void stack_mul (stack_t* box, int elem)
{
    elem =  stack_pop (box);
    elem *= stack_pop (box);
    stack_push (box, elem);
    STACK_CHECK
}

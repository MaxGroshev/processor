#include "CPU.h"

void processor (stack_t* box, processor* cpu, int elem)
{
    int* code_of_com = read_num_com();
    int  num_of_reg = 0; // cod of register
    for (int i = 0; code_of_com[i] != HLT; i++)
    {
        switch (code_of_com[i])
        {
            case PUSH:
                i++;
                elem = code_of_com[i];
                stack_push (box, elem);
                break;

            case PUSHR
                i++;
                code_of_reg = code_of_com[i];
                stack_push (box, cpu->registers[code_of_reg];
                break;

            case POPR
                i++;
                cpu->registers[code_of_com[i]] = stack_pop (box);
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
    FILE* num_com_bin = fopen ("../test-code.bin", "rb");
    for (int i = 0; !feof (num_com_bin); i++)
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
                printf ("Error of reallocating\n");
            }
        }

        int buffer = 0;
        fread (&buffer, sizeof (int), 1, num_com_bin);

        if (feof (num_com_bin))
        {
            continue;
        } // TO DO: dump processor (file is over)

        code_of_com[i] = buffer;
    }
    fclose (num_com_bin);
    return code_of_com;
}

//-----------------------------------------------------------------------------------------------------------

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
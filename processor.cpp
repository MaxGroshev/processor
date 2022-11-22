#include "processor.h"

void processor (stack_t* box, int elem)
{
    FILE* num_com = fopen ("test.code", "r");
    int code_of_com = 0;
    while (code_of_com != HLT)
    {
        fscanf (num_com, "%d", &code_of_com);
        switch (code_of_com)
        {
            case PUSH:
                fscanf (num_com, "%d", &elem);
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
                fclose (num_com);
                break;
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------

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

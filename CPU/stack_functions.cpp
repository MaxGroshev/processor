#include "CPU.h"

void stack_init (stack_t* box, stack_t* func_ret)
{
    box->data      = (type_of_elem*) calloc (box->capacity, sizeof (type_of_elem));
    func_ret->data = (type_of_elem*) calloc (10, sizeof (type_of_elem)); //size of ret value is not more then 10
    STACK_CHECK
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void stack_push (stack_t* box, double element)
{
    STACK_CHECK

    if (box->capacity - box->counter <= 10)
    {
        int* stack_resize = box->data;
        stack_resize = (int*) realloc (box->data, (box->counter + 20) * sizeof (type_of_elem));
        if (box->data != NULL)
        {
            box->data = stack_resize;
        }

        else
        {
            printf ("It is impossible to widen size of stack\n");
        }
        STACK_CHECK
    }
    box->data[box->counter++] = element * 100;
    if (box->capacity < box->counter)
    {
        box->capacity++;
    }

    STACK_CHECK
}

//----------------------------------------------------------------------------------------------------------------------------------------------

double stack_pop (stack_t* box)
{

    box->counter--;
    double element = box->data[box->counter];
    element = element / 100;
   // box->data[box->counter] = 0X7777777;
    STACK_CHECK

    return element;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void stack_delete (stack_t* box, stack_t* func_ret)
{
    free (box->data);
    free (func_ret->data);
}




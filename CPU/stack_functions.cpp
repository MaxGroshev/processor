#include "CPU.h"

void stack_init (stack_t* box, stack_t* func_ret)
{
    box->capacity = 10;
    box->data      = (type_of_elem*) calloc (box->capacity, sizeof (type_of_elem));
    MY_ASSERT        (box->data != NULL);
    set_canary       (box);
    func_ret->data = (type_of_elem*) calloc (10, sizeof (type_of_elem)); //size of ret value is not more then 10
    MY_ASSERT        (func_ret->data != NULL);
    STACK_CHECK
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void set_canary (stack_t* box) // this name is ok or not?
{
    if (box->counter == 0)
    {
        box->data[box->counter] = CANARY_VAL;
        box->counter++;
        //box->data[box->capacity + 1] = CANARY_VAL;
    }

    else
    {
        //any_stack->data[any_stack->capacity] = CANARY_VAL;
    }

}

//--------------------------------------------------------------------------------------------------------------------------------------------

void stack_push (stack_t* box, double element)
{
    STACK_CHECK

    if (box->capacity - box->counter <= 10)
    {
        box->capacity *= 2;
        printf ("%ld\n", box->capacity);
        int* stack_resize = box->data;
        stack_resize = (int*) realloc (box->data, (box->capacity) * sizeof (type_of_elem));
        MY_ASSERT (stack_resize != NULL);
        box->data = stack_resize;
        STACK_CHECK
    }
    box->data[box->counter++] = element * 100;

    // if (box->capacity < box->counter)
    // {
    //     box->capacity++;
    // }
    STACK_CHECK
}

//----------------------------------------------------------------------------------------------------------------------------------------------

double stack_pop (stack_t* box)
{

    box->counter--;
    double element = box->data[box->counter];
    element = element / 100;
    box->data[box->counter] = 0X7777777;
    STACK_CHECK

    return element;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void stack_delete (stack_t* box, stack_t* func_ret)
{
    free (box->data);
    free (func_ret->data);
}





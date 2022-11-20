<<<<<<< HEAD
#include "processor.h"
=======
#include "stack.h"
>>>>>>> refs/remotes/origin/main

void stack_init(stack_t* box, size_t capacity)
{
    box->data = (type_of_elem*)calloc(box->capacity, sizeof(type_of_elem));

    STACK_CHECK
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void stack_push(stack_t* box, type_of_elem element)
{
    STACK_CHECK

    if (box->capacity - box->counter <= 10)
    {
        int* stack_resize = box->data;
        stack_resize = (int*)realloc(box->data, (box->counter + 20) * sizeof(type_of_elem));
        if (box->data != NULL)
        {
            box->data = stack_resize;
        }
        else
        {
            printf("It is impossible to widen size of stack\n");
        }
        STACK_CHECK
    }
    box->data[box->counter++] = element;
    if (box->capacity < box->counter)
    {
        box->capacity++;
    }

    STACK_CHECK
}

//----------------------------------------------------------------------------------------------------------------------------------------------

int stack_pop(stack_t* box)
{

    box->counter--;
    type_of_elem element = box->data[box->counter];
    box->data[box->counter] = 0X7777777;
    STACK_CHECK

    return element;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void stack_delete(stack_t* box)
{
    free(box->data);
}




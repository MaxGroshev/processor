#include "processor.h"

int stack_check (stack_t* box)
{
    if (box->data == NULL)
    {
        return ERR_NULL_DATA;
    }

    if (sizeof (box->data[box->counter - 1]) != sizeof (type_of_elem))
    {
        return WRONG_INPUT;
    }

    if (box->counter == -1)
    {
        return OUT_OF_STACK;
    }
    return STACK_IS_OKEY;
}


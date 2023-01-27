#include "CPU.h"

void RAM_init (RAM* T_RAM)
{
    T_RAM->capacity = 200;
    T_RAM->data = (int*) calloc (T_RAM->capacity, sizeof (int));
    MY_ASSERT (T_RAM->data != NULL);

    for (int i = 0; i < T_RAM->capacity; i++)
    {
        T_RAM->data[i] = 1;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

void RAM_clean (RAM* T_RAM)
{
    free (T_RAM->data);
}


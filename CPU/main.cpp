#include "CPU.h"

int main()
{
    struct stack_t box   = {};
    struct processor cpu = {0, 0, 0, 0};
   // cpu.registers[3] = {0, 0, 0, 0};
    stack_init (&box);

    int elem = 0;
    dist_task (&box, &cpu, elem);

    stack_dump (&box, __FILE__, __FUNCTION__, __LINE__, 1);
    stack_delete (&box);
    return 0;
} //TO DO init registers




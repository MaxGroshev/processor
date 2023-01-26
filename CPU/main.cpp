#include "CPU.h"

int main()
{
    struct processor cpu = {};
    RAM_init (&cpu.T_RAM);
    memset (cpu.registers, -1, count_of_reg * sizeof (int));

    stack_init (&cpu.box, &cpu.func_ret);

    double elem = 0;
    dispatch_task (&cpu.box, &cpu.func_ret, &cpu, elem);

    stack_dump (&cpu.box, __FILE__, __FUNCTION__, __LINE__, 1);
    stack_delete (&cpu.box, &cpu.func_ret);
    return 0;
}




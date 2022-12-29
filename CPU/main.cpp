#include "CPU.h"

int main()
{
    struct processor cpu = {};
    const size_t count_of_reg = 4; //make global const
    memset (cpu.registers, -1, count_of_reg * sizeof (int));

    stack_init (&cpu.box, &cpu.func_ret);

    double elem = 0;
    dist_task (&cpu.box, &cpu.func_ret, &cpu, elem); //dispatch_task is better

    stack_dump (&cpu.box, __FILE__, __FUNCTION__, __LINE__, 1);
    stack_delete (&cpu.box, &cpu.func_ret);
    return 0;
}




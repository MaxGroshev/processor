#include "CPU.h"

int main()
{
    struct processor cpu = {};
    const size_t count_of_reg = 4;
    for (int i = 0; i < count_of_reg; i++)
    {
        cpu.registers[i] = {0};
    }

    stack_init (&cpu.box, &cpu.func_ret);

    double elem = 0;
    dist_task (&cpu.box, &cpu.func_ret, &cpu, elem);

    stack_dump (&cpu.box, __FILE__, __FUNCTION__, __LINE__, 1);
    stack_delete (&cpu.box, &cpu.func_ret);
    return 0;
}




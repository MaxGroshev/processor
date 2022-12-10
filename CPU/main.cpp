#include "CPU.h"

int main()
{
    struct stack_t box      = {}; //stack for elements
    struct stack_t func_ret = {}; //stack for returning points of functions
    struct processor cpu = {0, 0, 0, 0};
    stack_init (&box, &func_ret);

    int elem = 0;
    dist_task (&box, &func_ret, &cpu, elem);

    stack_dump (&box, __FILE__, __FUNCTION__, __LINE__, 1);
    stack_delete (&box, &func_ret);
    return 0;
} //TO DO init registers




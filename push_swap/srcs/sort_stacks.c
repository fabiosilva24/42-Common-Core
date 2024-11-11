#include "../include/push_swap.h"

void sort_stacks(t_stack_nodes **a, t_stack_nodes **b)
{
    if (a > 3 && !not_sorted)
        pa(*a);
    

    if (a == 3)
        sort_three(*a);
}

    
#include "../include/push_swap.h"


void sort_stacks(t_stack_nodes **a, t_stack_nodes **b)
{
    int size;
    
    size = stack_size(*a);

    if (size > 3 && !is_sorted(*a))
        pa(a, b);
    
    if (size == 2)
        sa(a);
        
    if (size == 3)
        sort_three(*a);
}
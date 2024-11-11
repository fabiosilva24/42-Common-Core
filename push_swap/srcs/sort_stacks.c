#include "../include/push_swap.h"

bool is_sorted(t_stack_nodes *stack)
{
    while (stack && stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return  (false);
        stack = stack->next;
    }
    return (true);
}

int stack_length(t_stack_nodes *stack)
{
    int i;

    i = 0;
    if (!*stack)
        return NULL;

    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}

void sort_stacks(t_stack_nodes **a, t_stack_nodes **b)
{
    int size;
    
    size = stack_size(*a);

    if (size > 3 && !is_sorted(*a))
        pa(a, b);
    

    if (size == 3)
        sort_three(*a);
}
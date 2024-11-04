#include "../include/push_swap.h"

t_stack_nodes *find_lastnode(t_struct_nodes *stack)
{
    if (!*stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

t_stacck_nodes find_maxnode(t_struct_nodes *stack)
{
    long    max;  //max stack number
    t_struct_nodes  *max_node; //max node box(not the number)

    max = LONG_MIN;
    if (!*stack)
        return (NULL);
    while (stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
    }
    return max_node;
}
    
    

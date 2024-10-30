#include "../include/push_swap.h"

t_stack_nodes find_lastnode(t_struct_nodes *stack)
{
    if (!*stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}
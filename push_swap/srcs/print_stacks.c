#include "../include/push_swap.h"

void print_stacks(t_stack_nodes *stack)
{
    while (stack)
    {
        ft_printf("%d ", stack->nbr);
        stack = stack->next;
    }
    ft_printf("\n");
}
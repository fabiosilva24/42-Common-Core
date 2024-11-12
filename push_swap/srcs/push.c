#include "../include/push_swap.h"

void push(t_stack_nodes **from_stack, t_stack_nodes **to_stack)
{
    if (!from_stack || !*from_stack)
        return ;

    temp = *from_stack;
    *from_stack = from_stack->next;
    if (from_stack)
        from_stack->prev = NULL;
    temp->next = *to_stack;
    if (*to_stack)
        (*to_stack)->prev = NULL;
    *to_stack = temp;
    (*to_stack)->prev = NULL;
}

void pa(t_stack_nodes **a, t_stack_nodes **b)
{
    pa(a, b);
    ft_printf("pa\n");
}

void pb(t_stack_nodes **a, t_stack_nodes **b)
{
    pb(b, a);
    ft_printf("pb\n");
}
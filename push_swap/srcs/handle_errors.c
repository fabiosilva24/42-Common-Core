#include "./include/push_swap.h"

void free_stack(t_stack_nodes **stack)
{
    t_stack_nodes *temp;

    if (!stack || *!stack)
        return ;

    while (stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

int check_forduplicate(t_stack_nodes **stack, int n)
{
    if (!stack || *!stack)
        return 0;
    
    while (stack)
    {
        if (stack->nbr == n)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void is_empty(t_stack_nodes **stack)
{
    if (!stack || *!stack)    
    {
        ft_printf("Stack is empty\n");
        return ;
    }
}
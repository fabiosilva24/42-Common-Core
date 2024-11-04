#include "../include/push_swap.h"

static  void reverse(t_struct_nodes **stack) //first becomes last       
{
    t_struct_nodes *last;
    t_struct_nodes *secound_last;

    if (!*stack || !(*stack)->next)
        return ;
    last = find_lastnode(*stack);
    secound_last = *stack;
    while (secound_last->next != last)   // while loops till secound_last is not the new last
    {
        secound_last = secound_last->next;
    }
    secound_last->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;      
    *stack = last;      //last is now the top node
}

void rra(t_struct_nodes **a)
{
    reverse(a);
    ft_printf("ra\n");
}

void rrb(t_struct_nodes **b)
{
    reverse(b);
    ft_printf("rb\n");
}

void rrr(t_struct_nodes **a, t_struct_nodes **b)
{
    reverse(a);
    reverse(b);
    ft_printf("rr\n");
}
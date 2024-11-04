#include "../include/push_swap.h"

static void rotate(t_struct_nodes **stack) //first becomes last       
{
    t_struct_nodes *last;
    t_struct_node *newest_last;

    if (!*stack || !(*stack)->next)
        return ;
    last = find_lastnode(*stack);
    newest_last = *stack;
    while (newest_last->next != last)    //while loop until newest_last is the new last node
    {
        newest_last = newest_last->next;
    }

    newest_last->next = NULL;  //detach last node from the list by making newset_last the newest last node

    last->next = *stack;
    last->prev = NULL;

    if (*stack)
        (*stack)->prev = last->node;  // Set the previous pointer of the current top to the new top
    
    *stack = last;

}

void ra(t_struct_nodes **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_struct_nodes **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_struct_nodes **a, t_struct_nodes **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
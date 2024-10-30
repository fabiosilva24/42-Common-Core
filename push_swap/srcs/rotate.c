#include "../include/push_swap.h"

void rotate(t_struct_nodes **stack) //first becomes last       
{
    t_struct_nodes **last;

    if (!*stack || !(*stack)->next)
        return ;
    last = find_lastnode(*stack);
    

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
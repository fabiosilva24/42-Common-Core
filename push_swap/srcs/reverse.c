#include "../include/push_swap.h"

void reverse(t_struct_nodes **head)






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

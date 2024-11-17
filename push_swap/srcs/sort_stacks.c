#include "../include/push_swap.h"

static void rotate_both(t_stack_nodes **a, t_stack_nodes **b)
{
    t_stack_nodes *cheapest_node;

    if (*b != cheapest_node->target_node)
        rr(a, b);
     check_median(*a);
     check_median(*b);
}

static void reverse_rotate_both(t_stack_nodes **a, t_stack_nodes **b)
{
    t_stack_nodes *cheapest_node;

    if (*b != cheapest_node->target_node)
    rrr(a, b);
    check_median(a);
    check_median(b);
}

static void move_b_to_a(t_stack_nodes **a, t_stack_nodes **b)
{
    prepare_to_push(a, (*b)->target_node, 'a');
    pa(a, b);
}
    void sort_stacks(t_stack_nodes **a, t_stack_nodes **b)
{
    int size;
    
    size = stack_size(*a);

    if (size > 3 && !is_sorted(*a))
        pa(a, b);
    
    if (size == 2)
        sa(a);
        
    if (size == 3)
        sort_three(*a);
}
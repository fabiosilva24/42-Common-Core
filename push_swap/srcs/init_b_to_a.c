#include "../include/push_swap.h"

static void set_target_b(t_stack_nodes *a, t_stack_nodes *b)
{
    t_stack_nodes *current_a;
    t_stack_nodes *target_node;
    long closest_bigger_nbr;
    
 
  while (a)
{
    closest_bigger_nbr = LONG_MAX;
    current_a = a;
    if (b->nbr < current_a->nbr
        && current_a->nbr < closest_bigger_nbr)
    {
       closest_bigger_nbr = current_a->nbr;
       target_node = current_a;
    }
     current_a = current_a->next;
}
if (closest_bigger_nbr == LONG_MAX)
    a->target_node = find_minnode(b);
else
    b->target_node = target_node;
    b = b->next;
}
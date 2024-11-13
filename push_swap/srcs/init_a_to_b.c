#include "../include/push_swap.h"

static void set_target_a(t_stack_nodes *a, t_stack_nodes *b)
{
    t_stack_nodes *current_b;
    t_stack_nodes *target_node;
    long closest_smaller_nbr;
    
 
  while (a)
{
    closest_smaller_nbr = LONG_MIN;
    current_b = b;
    if (a->nbr > current_b->nbr)
    {
       closest_smaller_nbr = current_b->nbr;
       target_node = closest_smaller_nbr;
       
     }
     current_b = current_b->next;
}
if (closest_smaller_nbr == LONG_MIN)
    a->target_node = find_maxnode(b);
else
    a->target_node = target_node;
    a = a->next;
}

void set_cheapest(t_stack_nodes **stack)
{
    t_stack_nodes **cheapest_value;

    cheapest_value = get_cheapest(stack);

    if (!stack)
        return ;  
    while (stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;  //supdate the cheapest value to the current node push cost
            cheapest_node = stack; //assign current node as the cheapest node so far
        }
        stack = stack->next; //move to the next node for comparision
    }
    cheapest_node->cheapest = true;  //if no cheaper node found update cheapest to true
}
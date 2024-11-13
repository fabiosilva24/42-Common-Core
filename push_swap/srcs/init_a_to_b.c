#include "../include/push_swap.h"

void set_target(t_stack_nodes *a, t_stack_nodes *b)
{
    t_stack_nodes *current_b;
    t_stack_nodes *target_node;

    if (!a || !b)
      return ;
 b = current_b;

  while (a)
{
    if (a->push_cost < a->cheapest_node)
    {
       a->push_cost = a->cheapest_node;
       a = a->next;
     }
     cheapest_value = true;
     
    
   

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
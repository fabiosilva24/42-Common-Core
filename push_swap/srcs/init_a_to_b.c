#include "../include/push_swap.h"


void set_cheapest(t_stack_nodes **stack)
{
    t_stack_nodes **cheapest_value;

    cheapest_value = get_cheapest(stack);
    
    if (!stack)
        return ;

    
    while (stack)
    {
        if (stack->push_cost < cheapest_value)
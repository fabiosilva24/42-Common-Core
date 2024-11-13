#include "../include/push_swap.h"

t_stack_nodes *find_lastnode(t_struct_nodes *stack)
{
    if (!*stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

bool is_sorted(t_stack_nodes *stack)
{
    while (stack && stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return  (false);
        stack = stack->next;
    }
    return (true);
}

int stack_length(t_stack_nodes *stack)
{
    int i;

    i = 0;
    if (!*stack)
        return NULL;

    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}

t_stack_nodes find_maxnode(t_struct_nodes *stack)
{
    long    max;  //max stack number
    t_struct_nodes  *max_node; //pointer that points to the biggest number

    max = LONG_MIN;  //long min so we dont need extra conditions or check for negative and positive numbers
    if (!*stack)
        return (NULL);
    while (stack)
    {
        if (stack->nbr > max)     //nbr > long_min  imagine nbr is -2 > long_min so -2 is the max so far
        {
            max = stack->nbr;   //ex:max = -2
            max_node = stack;  //biggest number = node
        }
        stack = stack->next;     // move to the next node
    }
    return max_node; //returns pointer to the biggest number
}
    
    

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:42:31 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:42:31 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_nodes *find_lastnode(t_stack_nodes *stack)
{
    if (!stack)
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
    if (!stack)
        return (NULL);

    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}

t_stack_nodes *find_maxnode(t_stack_nodes *stack)
{
    long    max;  //max stack number
    t_stack_nodes  *max_node; //pointer that points to the biggest number

    max = LONG_MIN;  //long min so we dont need extra conditions or check for negative and positive numbers
    if (!stack)
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

t_stack_nodes *find_minnode(t_stack_nodes *stack)
{
    long    min;  //min stack number
    t_stack_nodes  *min_node; //pointer that points to the smallest number

    
    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < min)
        {     
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;     // move to the next node
    }
    return min_node; //returns pointer to the smallest number
}

void init_nodes_a(t_stack_nodes *a, t_stack_nodes *b)
{
    check_median(b);
    check_median(a);
    set_target_a(b);
}

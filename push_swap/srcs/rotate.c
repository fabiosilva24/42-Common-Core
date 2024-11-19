/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:42:04 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:42:04 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void rotate(t_stack_nodes **stack) //first becomes last       
{
    t_stack_nodes *last;
    t_stack_nodes *newest_last;

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
        (*stack)->prev = last;  // Set the previous pointer of the current top to the new top
    
    *stack = last;

}

void ra(t_stack_nodes **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_stack_nodes **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_stack_nodes **a, t_stack_nodes **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
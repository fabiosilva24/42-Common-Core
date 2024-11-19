/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:41:59 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:41:59 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static void	reverse(t_stack_nodes **stack) //Define a funtion that rotates a stack's bottom node, to the top
{
	t_stack_nodes	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next)
		return ;
	last = find_lastnode(*stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last; 
	last->next->prev = last; //Update the current last node of the stack
}

void rra(t_stack_nodes **a)
{
    reverse(a);
    ft_printf("rra\n");
}

void rrb(t_stack_nodes **b)
{
    reverse(b);
    ft_printf("rrb\n");
}

void rrr(t_stack_nodes **a, t_stack_nodes **b)
{
    reverse(a);
    reverse(b);
    ft_printf("rrr\n");
}
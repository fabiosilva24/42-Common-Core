/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:57:10 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/20 17:57:10 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack_nodes **stack)
{
	t_stack_nodes	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_lastnode(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_nodes **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_nodes **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_nodes **a, t_stack_nodes **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

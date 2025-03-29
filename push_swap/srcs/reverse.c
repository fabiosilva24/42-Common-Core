/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:57:00 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/20 17:57:00 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse(t_stack_nodes **stack)
{
	t_stack_nodes	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_lastnode(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_nodes **a)
{
	reverse(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_nodes **b)
{
	reverse(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_nodes **a, t_stack_nodes **b)
{
	reverse(a);
	reverse(b);
	ft_printf("rrr\n");
}

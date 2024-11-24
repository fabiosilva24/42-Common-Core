/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:56:45 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/20 17:56:45 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack_nodes **to_node, t_stack_nodes **from_node)
{
	t_stack_nodes	*push_node;

	if (!*from_node) 
		return ;
	push_node = *from_node;
	*from_node = (*from_node)->next;
	if (*from_node)
		(*from_node)->prev = NULL;
	push_node->prev = NULL;
	if (!*to_node)
	{
		*to_node = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *to_node; 
		push_node->next->prev = push_node;
		*to_node = push_node;
	}
}

void pa(t_stack_nodes **a, t_stack_nodes **b)
{
    push(a, b);
    ft_printf("pa\n");
}

void pb(t_stack_nodes **b, t_stack_nodes **a)
{
    push(b, a);
    ft_printf("pb\n");
}
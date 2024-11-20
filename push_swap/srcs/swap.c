/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:58:22 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/20 17:58:22 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack_nodes	**head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_nodes	**a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_nodes	**b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_nodes	**a, t_stack_nodes	**b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

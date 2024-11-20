/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:41 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/20 17:55:41 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_median(t_stack_nodes	*stack)
{
	int	median;
	int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack_nodes	*a, t_stack_nodes	*b)
{
	t_stack_nodes	*current_b;
	t_stack_nodes	*target_node;
	long	closest_smaller_nbr;

	while (a)
	{
		closest_smaller_nbr = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > closest_smaller_nbr)
			{
				closest_smaller_nbr = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller_nbr == LONG_MIN)
			a->target_node = find_maxnode(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_cheapest(t_stack_nodes	*stack)
{
	long			cheapest_value;
	t_stack_nodes	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost; //supdate the cheapest value to the current node push cost
			cheapest_node = stack; //assign current node as the cheapest node so far
		}
		stack = stack->next; //move to the next node for comparision
	}
	cheapest_node->cheapest = true;//if no cheaper node found update cheapest to true
}

static void	cost_analysis_a(t_stack_nodes	*a, t_stack_nodes	*b)
{
	int	a_length;
	int	b_length;

	a_length = stack_length(a);
	b_length = stack_length(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = a_length - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else // if a node is indeed above the median and its target b node is below median
			a->push_cost += b_length - (a->target_node->index); // update a node push cost , the sum of  (its current index) + (b stack length - its target b node index)
		a = a->next;
	}
}

void	init_nodes_a(t_stack_nodes	*a, t_stack_nodes	*b)
{
	check_median(a);
	check_median(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

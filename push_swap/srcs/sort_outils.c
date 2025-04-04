/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:39:57 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/25 15:41:48 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_both(t_stack_nodes	**a,
				t_stack_nodes	**b, t_stack_nodes	*cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b);
	check_median(*a);
	check_median(*b);
}

static void	reverse_rotate_both(t_stack_nodes	**a,
				t_stack_nodes	**b, t_stack_nodes	*cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
	check_median(*a);
	check_median(*b);
}

static void	move_a_to_b(t_stack_nodes	**a, t_stack_nodes	**b)
{
	t_stack_nodes	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prepare_to_push(a, cheapest_node, 'a');
	prepare_to_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	move_b_to_a(t_stack_nodes	**a, t_stack_nodes	**b)
{
	prepare_to_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	min_ontop(t_stack_nodes	**a)
{
	while ((*a)->nbr != find_minnode(*a)->nbr)
	{
		if (find_minnode(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

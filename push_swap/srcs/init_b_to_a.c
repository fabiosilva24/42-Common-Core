/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:41:32 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:41:32 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void set_target_b(t_stack_nodes *a, t_stack_nodes *b)
{
    t_stack_nodes *current_a;
    t_stack_nodes *target_node;
    long closest_bigger_nbr;
    
 
    while (b)
    {
        closest_bigger_nbr = LONG_MAX;
        current_a = a;
        if (current_a->nbr > b->nbr
            && current_a->nbr < closest_bigger_nbr)
        {
        closest_bigger_nbr = current_a->nbr;
        target_node = current_a;
        }
        current_a = current_a->next;
    }
    if (closest_bigger_nbr == LONG_MAX)
            b->target_node = find_minnode(b);
    else
            b->target_node = target_node;
    b = b->next;
}

void init_nodes_b(t_stack_nodes *a, t_stack_nodes *b)
{
    check_median(a);
    check_median(b);
    set_target_b(a, b);
}
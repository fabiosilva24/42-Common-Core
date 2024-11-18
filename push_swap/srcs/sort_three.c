/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:42:10 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:42:10 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three(t_stack_nodes **a)  //max number on bottom if need do swap a
{
    t_stack_nodes *biggest;
    t_stack_nodes *bottom;

    biggest = find_maxnode(*a);

    if (biggest == *a)
        ra(a);
    else if ((*a)->next == biggest)
        rra(a);
    if ((*a)->nbr > (*a)->next->nbr)    //check if the bottom node is the biggest but the top node is higher than the secound node imagine nbr is 12 top node and the scound is 10 so you swap so now its  10 12 50
        sa(a);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:41:55 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:41:55 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void push(t_stack_nodes **from_stack, t_stack_nodes **to_stack)
{
    t_stack_nodes *temp; // Declare temp

    if (!from_stack || !*from_stack)
        return ;

    temp = *from_stack;
    *from_stack = (*from_stack)->next;
    if (*from_stack)
        (*from_stack)->prev = NULL;
    temp->next = *to_stack; 
    if (*to_stack)
        (*to_stack)->prev = temp; // Fix this line to set prev to temp
    *to_stack = temp;
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
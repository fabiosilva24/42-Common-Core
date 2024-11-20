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

static void	rotate(t_stack_nodes **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack_nodes	*last_node; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = find_lastnode(*stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}	

/*static void rotate(t_stack_nodes **stack) //first becomes last       
{
    t_stack_nodes *last;
    t_stack_nodes *newest_last;

    if (!*stack || !(*stack)->next)
        return ;
    last = find_lastnode(*stack);
    ft_printf("%d", last->nbr);
    newest_last = *stack;
    ft_printf("%d", newest_last->nbr);
    while (newest_last->next != last)    //while loop until newest_last is the new last node
    {
        newest_last = newest_last->next;
    }
    ft_printf("%d", newest_last->nbr);
    newest_last->next = NULL;  //detach last node from the list by making newset_last the newest last node

    last->next = *stack;
    last->prev = NULL;

    if (*stack)
        (*stack)->prev = last;  // Set the previous pointer of the current top to the new top
    
    *stack = last;
    ft_printf("hello:%d%d%d", (*stack)->nbr, (*stack)->next->nbr, (*stack)->next->next->nbr);
}*/

void ra(t_stack_nodes **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_stack_nodes **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_stack_nodes **a, t_stack_nodes **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
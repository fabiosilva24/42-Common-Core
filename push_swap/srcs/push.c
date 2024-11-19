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

static void	push(t_stack_nodes **to_node, t_stack_nodes **from_node) //Define a function that pushes a top node, from one stack to another's top node
{
	t_stack_nodes	*push_node;

	if (!*from_node) 
		return ;
	push_node = *from_node; //The top node to push is assigned to the `t_stack_node` variable
	*from_node = (*from_node)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*from_node)
		(*from_node)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*to_node) //Check if the other stack is empty
	{
		*to_node = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *to_node ; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*to_node = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
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
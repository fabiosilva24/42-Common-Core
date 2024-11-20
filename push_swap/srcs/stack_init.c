/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:57:59 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/20 17:57:59 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long ft_atol(const char *str)   //ascii to long
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
            str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return (sign * result);
}

static void	append_node(t_stack_nodes **stack, int n)
{
    t_stack_nodes *last_node;
    t_stack_nodes *node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack_nodes));
    if (!node)
        return ;
    node->next = NULL;
    node->nbr = n;
    node->cheapest = 0;
    if (!(*stack)) // If the stack is empty, initialize the first node
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_lastnode(*stack);
        last_node->next = node;     //seting last_node to next so now the next is the last
        node->prev = last_node;    //nodes->prev is last node since node = next node node->prev last
    }
}
void init_stack_a(t_stack_nodes **stack, char **argv)
{
    int i;
    long value;

    i = 0; 
    while (argv[i])              
    {
        if (syntax_error(argv[i]))
            free_errors(stack);
        value = ft_atol(argv[i]);
        if (value < INT_MIN || value > INT_MAX)   //check for overflow
            free_errors(stack);
        if (error_duplicate(*stack, (int)value))
            free_errors(stack);
        append_node(stack, (int)value);
        i++;
    }
}


t_stack_nodes *get_cheapest(t_stack_nodes *stack)
{
    if  (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
                return stack;
        stack = stack->next;
    }
    return (NULL);
}

void prepare_to_push(t_stack_nodes **stack, t_stack_nodes *top, char stack_name)
{

while (*stack != top)
{
    if (stack_name == 'a')
    {
        if (top->above_median)
            ra(stack);
        else
            rra(stack);
    }
    else if (stack_name == 'b')
    {
        if (top->above_median)
            rb(stack);
        else
            rrb(stack);
    }
}
}
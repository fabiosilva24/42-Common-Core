#include "../include/push_swap.h"
#include <stdio.h>

static long ft_atol(const char *str)   //ascii to long
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || *str >= 9 && *str <= 13)
            str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (sign * result);
}

static void	append_node(t_stack_nodes **stack, int n)
{
    t_stack_node *last_nodes;
    t_stack_node *node;

    if (!*stack)
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
        last_node = find_lastnode;
        last_node->next = node;     //seting last_node to next so now the next is the last
        node->prev = last_node;    //nodes->prev is last node since node = next node node->prev last
    }
}
void init_stack_a(t_stack nodes **stack)
{
    if (!*stack)
        return ;
    
}


t_stack_nodes *get_cheapest(t_stack nodes **stack)
{
    if  (*stack)
        return ;
    
    while (stack)
    {
        if (stack->cheapest)
                return stack;
        stack = stack->next;
    }
    return NULL;
}




        



/*int main(void)
{
    const char *str = "1234567891111111111111111";
    long test = ft_atol(str);

    printf("converted number: %ld\n", test);
}/*
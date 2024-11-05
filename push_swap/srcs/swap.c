#include "./include/push_swap.h"

void swap(t_struct_nodes **head)
{
    if (!*head || !(*head)->next)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev;
    (*head)->next = (*head)-> prev;
    (*head)->prev = NULL;
}

void sa(t_struct_nodes **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_struct_node **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_struct_node **a, t_struct_node **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
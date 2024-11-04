#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../libs/libft/libft.h"

typedef struct s_stack_nodes
{
    int min;
    int max;
    int index;
    int nbr;
    int push_cost;
    bool    cheapest;
    bool    above_median;
    struct s_stack *target_node;
    struct s_stack  *next; // pointer to the next node in the stack
    struct s_stack  *prev; // pointer to the previous node in the stack
}			t_stack_nodes;


//handle errors

//stack init
static long ft_atol(const char *str); //int to long

//nodes init

//stack utils
t_stack_nodes *find_lastnode(t_struct_nodes *stack); //searches a stack and return the last node
t_stack_nodes *find_maxnode(t_struct_nodes *stack); //searches a stack and returns the node with the biggest number    
//commands
static void rotate(t_struct_nodes **stack); //first to last node
static void reverse(t_struct_node **stack); //last to first node
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

//algorithms
void sort_three(t_stack_nodes **a);

#endif

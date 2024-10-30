#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/libft.h"

typedef struct s_stack_nodes
{
    int min;
    int max;
    int push_cost;
    bool    cheapest;
    bool    above_median;
    struct s_stack *target_node;
    struct s_stack  *next; // pointer to the next node in the stack
    struct s_stack  *prev; // pointer to the previous node in the stack
}			t_stack_nodes;


//handle errors

//stack init
static long ft_atol(const char *str);

//nodes init

//stack utils
t_stack_nodes find_lastnode(t_struct_nodes *stack);
//commands

//algorithms

#endif

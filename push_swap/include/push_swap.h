/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:43:43 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/25 15:51:55 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../libs/libft/libft.h"

typedef struct s_stack_nodes
{
	int						min;
	int						max;
	int						index;
	int						nbr;
	int						push_cost;
	bool					cheapest;
	bool					above_median;
	struct s_stack_nodes	*target_node;
	struct s_stack_nodes	*next;
	struct s_stack_nodes	*prev;
}			t_stack_nodes;

int				error_duplicate(t_stack_nodes *stack, int n);
int				syntax_error(const char *str);
void			free_errors(t_stack_nodes **a);
void			free_argv(char **argv);
void			free_stack(t_stack_nodes **stack);

//stack init
void			init_stack_a(t_stack_nodes **stack, char **argv);
char			**modified_ftsplit(char *s, char c);

void			move_b_to_a(t_stack_nodes **a, t_stack_nodes **b);
void			check_median(t_stack_nodes *stack);
void			init_nodes_b(t_stack_nodes *a, t_stack_nodes *b);
void			init_nodes_a(t_stack_nodes *a, t_stack_nodes *b);
void			set_cheapest(t_stack_nodes *stack);
void			prepare_to_push(t_stack_nodes **stack,
					t_stack_nodes	*top, char stack_name);
t_stack_nodes	*get_cheapest(t_stack_nodes *stack);
t_stack_nodes	*find_minnode(t_stack_nodes *stack);
t_stack_nodes	*find_lastnode(t_stack_nodes *stack);
t_stack_nodes	*find_maxnode(t_stack_nodes *stack);
int				stack_length(t_stack_nodes *stack);
bool			is_sorted(t_stack_nodes *stack);

void			sa(t_stack_nodes **a);
void			sb(t_stack_nodes **b);
void			ss(t_stack_nodes **a, t_stack_nodes **b);
void			ra(t_stack_nodes **a);
void			rb(t_stack_nodes **b);
void			rr(t_stack_nodes **a, t_stack_nodes **b);
void			rra(t_stack_nodes **a);
void			rrb(t_stack_nodes **b);
void			rrr(t_stack_nodes **a, t_stack_nodes **b);
void			pa(t_stack_nodes **a, t_stack_nodes **b);
void			pb(t_stack_nodes **b, t_stack_nodes **a);

void			sort_three(t_stack_nodes **a);
void			sort_stacks(t_stack_nodes **a, t_stack_nodes **b);

#endif

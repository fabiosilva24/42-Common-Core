#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack_nodes **a;
    t_stack_nodes **b;

    a = NULL;
    b = NULL;
    
	if (argc == 1 && !argv[1][0])
        return (1);
    else if (argc == 2)
    argv = ft_split(argv[1], ' ');
    init_stack_a(&a, argv + 1) //cause we want to start at ex: "19 23 21 42"
    if (!is_sorted(a))
    {
        if (stack_length(a) == 2)
            sa(&a);
        else if (stack_length(a) == 3)
            sort_three(&a);
        else
            sort_stacks(&a, &b);
    }
    free_stack(&a);
    return 0;
}

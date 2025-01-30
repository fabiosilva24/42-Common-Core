#include "../include/minishell.h"

void execute_echo(t_token *tokens)
{
    int arg_count;
    t_token *current;
    char **args;

    arg_count = 0;
    current = tokens->next;
    args = malloc(sizeof(char *) * (arg_count + 1));

    args[arg_count++] = "echo";

    while (current)
    {
        args[arg_count++] = current->value;
        current = current->next;
    }
    args[arg_count] = NULL;

    my_echo(arg_count, args);
    free(args);
}

void my_echo(int argc, char **argv)
{
    int newline = 1; // print a newline default
    int i = 1;

    if (argc > 1 && strcmp(argv[1], "-n")== 0)
    {
        newline = 0;
        i = 2; //when using echo -n it skips the newline
    }
    while (i < argc)
    {
        printf("%s", argv[i]);
        if (i < argc - 1)
            printf(" "); //separate arguments with space
        i++;
        if (newline)
        {
            printf("\n");
        }
    }
}

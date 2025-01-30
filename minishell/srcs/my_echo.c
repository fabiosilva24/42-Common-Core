#include "../include/minishell.h"

void my_echo(int argc, char **argv)
{
    int i;
    int newline;

    i = 1;
    newline = 1;

    if (argc > 1 && strcmp(argv[i], "-n") == 0)
    {
        newline = 0;
        i++;
    }

    while (i < argc)
    {
        printf("%s", argv[i]);
        if (i < argc - 1)
        {
            printf(" ");
        }
        i++;
    }

    if (newline)
    {
        printf("\n");
    }
}
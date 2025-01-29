#include "../include/minishell.h"

void my_echo(int argc, char **argv)
{
    int newline = 1 // print a newline default
    int i = 1;

    if (argc > 1 && strcmp(argv[1], "-n")== 0)
    {
        newline = 0;
        i = 2; //when using echo -n it skips the newline
    }
    while (i++ < argc)
    {
        printf("%s", argv[i]);
        if (i < argc - 1)
        {
            printf(" "); //separate arguments with space
        }
        if (newline)
        {
            printf("\n")
        }
    }
}

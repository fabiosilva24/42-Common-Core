#include "../include/minishell.h"


static void display_prompt()
{
    printf("minishell> ");
    fflush(stdout);
}
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t stringread;
    (void)argv;
    if (argc != 1)
    {
        printf("Usage: ./minishell argument\n");
        return (1);
    }
    while (1)
    {
        display_prompt();
        stringread = getline(&line, &len, stdin);
        if (stringread == -1)
        {
            free(line);
            break;
        }
    }
    return 0;
    
}
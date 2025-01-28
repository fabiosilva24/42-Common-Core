#include "../include/minishell.h"


static void display_prompt()
{
    printf("minishell> ");
    fflush(stdout);
}
int main(int argc, char **argv)
{
    char *line;
    size_t len;
    ssize_t stringread;

    line = NULL;
    len = 0;
    
    (void)argv;
    if (argc != 1)
    {
        printf("Usage: ./minishell argument\n");
        return (1);
    }
    print_banner();
    while (1)
    {
        display_prompt();
        stringread = getline(&line, &len, stdin);
        if (stringread == -1)
        {
            free(line);
            break;
        }

        if (strchr(line, '\"'))
        {
            double_quotes(line);
        }
        else
        {
            printf("%s", line);
        }
    }
    return 0;
    
}
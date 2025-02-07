/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:56:43 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/02/07 12:29:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    handle_sigint(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n", 1);
    rl_redisplay();
}

int main(int argc, char **argv)
{
    t_minishell shell;
    char *line;
    int i;

    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);

    shell.environment = get_environment();
    (void)argv;
    if (argc != 1)
    {
        printf("Usage: ./minishell to enter minishell\n");
        return (1);
    }
    print_banner();
    while (1)
    {
        line = readline("minishell$ ");
        if (!line)
            break;
        if (*line)
            add_history(line);
        t_token *tokens = tokenize_input(line);
        if (tokens && strcmp(tokens->value, "echo") == 0)
        {
            // Convert tokens to argc and argv format
            int token_count = 0;
            t_token *temp = tokens;
            while (temp)
            {
                token_count++;
                temp = temp->next;
            }

            char **argv = malloc((token_count + 1) * sizeof(char *));
            i = 0;
            while (tokens)
            {
                argv[i++] = tokens->value;
                tokens = tokens->next;
            }
            argv[i] = NULL;

            my_echo(token_count, argv);
            free(argv);
        }
        free_tokens(tokens);
        free(line);
    }
    return 0;
}

/*int main(int argc, char **argv)
{
    t_minishell shell;
    char *line;

    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);

    shell.environment = get_environment();
    (void)argv;
    if (argc != 1)
    {
        printf("Usage: ./minishell to enter minishell\n");
        return (1);
    }
    print_banner();
    while (1)
    {
        my_echo(argc, argv);
        line = readline("minishell$ ");
        if (!line)
            break;
        if (*line)
            add_history(line);
        t_token *tokens = tokenize_input(line);
        if (tokens && strcmp(tokens->value, "echo") == 0)
            execute_echo(tokens);
        free_tokens(tokens);
        free(line);
    }
    return 0;
}*/
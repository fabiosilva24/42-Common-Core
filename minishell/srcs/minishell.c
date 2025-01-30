/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:56:43 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/30 19:22:38 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void display_prompt()
{
    printf("minishell$ ");
    fflush(stdout);
}
int main(int argc, char **argv)
{
    t_minishell shell;
    char *line;
    size_t len;
    ssize_t stringread;

    line = NULL;
    len = 0;
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
        display_prompt();
        my_echo(argc, argv);
        stringread = getline(&line, &len, stdin);
        if (stringread == -1)
        {
            free(line);
            break;
        }
        line[strcspn(line, "\n")] = 0;
        t_token *tokens = tokenize_input(line);
        if (tokens && strcmp(tokens->value, "echo") == 0)
            execute_echo(tokens);
        if (strchr(line, '\"'))
            double_quotes(line);
        if (strchr(line, '\''))
            single_quotes(line);
        free_tokens(tokens);
    }
    return 0;   
}

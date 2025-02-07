/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:57:01 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/02/07 12:26:16 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void execute_echo(t_token *tokens)
{
    int arg_count;
    t_token *current;
    char **args;
    int i;

    i = 1;
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
    while (i < arg_count)
    {
        parse_input(args[1]);
        if (i < arg_count - 1)
            printf(" ");
        i++;
    }
    printf("\n");
    free(args);
}

void my_echo(int argc, char **argv)
{
    int newline; // print a newline default
    int i;

    newline = 1;
    i = 1;

    if (argc > 1 && strcmp(argv[1], "-n")== 0)
    {
        newline = 0;
        i = 2; //when using echo -n it skips the newline
    }
    while (i < argc)
    {
        parse_input(argv[i]);
        if (i < argc - 1)
            printf(" "); //separate arguments with space
        i++;
    }
    if (newline)
    {
        printf("\n");
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:56:31 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/02/07 12:22:49 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static e_token_type token_determinator(char *token, int is_first)
{
    if (is_first)
        return (TOKEN_ARGUMENT);
    if (strcmp(token, ">") == 0 || strcmp(token, "<") == 0 ||
        strcmp(token, ">>") == 0 || strcmp(token, "<<") == 0)
        return (TOKEN_REDIRECT);
    if (strcmp(token, "|") == 0)
        return (TOKEN_PIPE);
    return (TOKEN_ARGUMENT);
}
t_token *create_token(char *value, e_token_type type)
{
    t_token *new_token = (t_token *)malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->value = strdup(value);
    new_token->type = type;
    new_token->next = NULL;
    return (new_token);
}

/*t_token *tokenize_input(char *line)
{
    t_token *head;
    t_token *current;
    char *token;
    int is_first;

    head = NULL;
    current = NULL;
    is_first = 1;

    while (*line && isspace(*line))
        line++;
    token = ft_strtok(line, " \t");
    while (token)
    {
        e_token_type type = token_determinator(token, is_first);
        t_token *new_token = create_token(token, type);
        if (!head)
            head = new_token;
        else
            current->next = new_token;
        current = new_token;
        token = ft_strtok(NULL, " \t");
        is_first = 0;
    }
    return (head);
}*/

#include "../include/minishell.h"

t_token *tokenize_input(char *line)
{
    t_token *head = NULL;
    t_token *current = NULL;
    char *token;
    int is_first = 1;
    int in_double_quotes = 0;
    int in_single_quotes = 0;
    char *start = line;

    while (*line)
    {
        if (*line == '\"' && !in_single_quotes)
        {
            in_double_quotes = !in_double_quotes;
        }
        else if (*line == '\'' && !in_double_quotes)
        {
            in_single_quotes = !in_single_quotes;
        }   
        else if (ft_isspace(*line) && !in_double_quotes && !in_single_quotes)
        {
            if (start != line)
            {
                *line = '\0';
                token = start;
                e_token_type type = token_determinator(token, is_first);
                t_token *new_token = create_token(token, type);
                if (!head)
                    head = new_token;
                else
                    current->next = new_token;
                current = new_token;
                is_first = 0;
            }
            start = line + 1;
        }
        line++;
    }

    if (start != line)
    {
        token = start;
        e_token_type type = token_determinator(token, is_first);
        t_token *new_token = create_token(token, type);
        if (!head)
            head = new_token;
        else
            current->next = new_token;
    }

    return head;
}



void *free_tokens(t_token *tokens)
{
    while (tokens)
    {
        t_token *next = tokens->next;
        free(tokens->value);
        free(tokens);
        tokens = next;
    }
    return NULL;

}
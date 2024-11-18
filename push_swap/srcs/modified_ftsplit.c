/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_ftsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:41:42 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:41:42 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_words(char *s, char separator)
{
	int count;
	bool	inside_word;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == seperator)
			++s;
		while (*s != seperator && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			s++;
		}
	}
	return (count);
}
static char	*get_next_word(char *s, char separator)
{
	static int	cursor = 0;
	char	*next_s;
	int			len;
	int			i;

	len = 0;
	i = 0;

	while (s[cursor] == separator)
		++cursor;
	while ((s[cursor + len] != separator) && str[cursor + len])
		++len;
	next_s = malloc(len * sizeof(char) + 1);
	if (NULL == next_s)
		return (NULL);
	while ((s[cursor] != separator) && s[cursor])
		next_s[i++] = s[cursor++];
	next_s[i] = '\0';
	return (next_s);
}


char	**modified_ftsplit(char *s, char separator)
{
	int		words_number;
	char	**vector_strings;
	int			i;
	
	i = 0;
	words_number = count_words(s, seperator);
	vector_strings = malloc(sizeof(char *) * (words_number + 2));  //mimic argument vector
	if (!s || !result)
		return (NULL);
	i = 0;

	if (NULL = vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings)
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, seperator);
	}
}
			
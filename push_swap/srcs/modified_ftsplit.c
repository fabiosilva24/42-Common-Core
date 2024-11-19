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


	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == separator)
			++s;
		while (*s != separator && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
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
	while ((s[cursor + len] != separator) && s[cursor + len])
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
	words_number = count_words(s, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (words_number + 2));  //mimic argument vector
	if (NULL == vector_strings)
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
		vector_strings[i++] = get_next_word(s, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:50:01 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/29 19:34:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	
	while(str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, const const *s2)
{
	int i;
	int j;
	char *str;
	size_t total_len;
	
	i = 0;
	j = 0;
	total_len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str)
	return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
char	*ft_strcpy(char *dest, const char *src)
{	
	int i;
	
	i = 0;
	
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

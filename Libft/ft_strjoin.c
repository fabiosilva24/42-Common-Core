/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:03:17 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/28 19:06:01 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	new_len;
	char	*new_str;
	size_t	i;
	size_t new_len;
	
	i = 0;
	len_s1 = 0;
	len_s2 = 0;

	while (s1[len_s1] != '\0')
		len_s1++;
	while (s2[len_s2] != '\0')
		len_s2++;
	
	new_len = len_s1 + len_s2;	
	*new_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	while (i < len_s1)
	{
		i++;
		new_str[i] = s1[i];
	}
	while (i < len_s2)
	{
		new_str[len_s1 + i] = s2[i];
		i++;
	}
	new_str[new_len] = '\0';
	
	return new_str;
}
	

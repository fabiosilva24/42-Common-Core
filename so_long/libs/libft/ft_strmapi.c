/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:00:14 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/03/09 13:44:21 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;

	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (s[len])
	{
		result[len] = (*f)(len, s[len]);
		len++;
	}
	result[len] = '\0';
	return (result);
}	

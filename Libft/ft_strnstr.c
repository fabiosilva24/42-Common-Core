/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:44:08 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/03/09 15:10:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				j;
	int				start;

	i = 0;
	j = 0;
	if (*needle == 0 || needle == NULL)
		return ((char *)haystack);
	while (i < len && haystack[i] != 0)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			start = i;
			while ((i + j) < len && needle[j] != 0 \
			&& needle[j] == haystack[i + j])
				j++;
			if (needle[j] == 0)
				return ((char *)(haystack + start));
		}
		i++;
	}
	return (NULL);
}	

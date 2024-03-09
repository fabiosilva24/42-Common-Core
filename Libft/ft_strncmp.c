/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:55 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/03/09 14:42:50 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*str1 != *str2)
		{
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		}
		if (*str1 == '\0')
		{
			break ;
		}
		str1++;
		str2++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void) 
{
	char str1[15] = "ABCDEF";
	char str2[15] = "abcdef";
	int start;
	
	start = (ft_strncmp(str1, str2, 5));
	
	if (start > 0)
{
	printf("str2 is less than str1");
}
	else if (start < 0)
{
	printf("str1 is less than str2");
}
	else if (start == 0)
{
	printf("str1 is equal to str2");
}
}*/

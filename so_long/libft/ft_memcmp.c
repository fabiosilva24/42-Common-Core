/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:59:09 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/22 16:21:17 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*p1 = str1, *p2 = str2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
		i++;
	}
	return (0);
}

/*int main (void)
{
    char str1[15] = "abcdef";
    char str2[15] = "ABCDEF";
    int strt;

    strt = ft_memcmp(str1, str2, 5);

	if (strt > 0) 
	{
        	printf("str2 is less than str1");
    	} 
	else if(strt < 0) 
	{
        	printf("str1 is less than str2");
	} 
	else 
	{
        	printf("str1 is equal to str2");
	}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:16:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/26 18:55:41 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p = str;

	while (n-- != 0)
	{
		if (*p++ == (unsigned char)c)
			return ((void *)(p - 1));
	}
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
	char data[] = {'q','r','t','p','a','x'};
	char *pos = ft_memchr(data,'p',7);
	printf("pos[0] = %c\n", pos[0]);
	printf("pos[1] = %c\n",pos[1]);
}*/

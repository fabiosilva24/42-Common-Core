/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:08:43 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/26 14:35:21 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{	
	unsigned char	*d;

	d = str;
	while (n--)
	{
		*d++ = (unsigned char)c;
	}
	return (str);
}
/*int main(void)
{
	char buf[0xff];
	ft_memset(buf, 0, 0xff);
	ft_memset(buf, 'A', 20);
	ft_memset(buf + 20, 'B', 20);
	printf("%s\n", buf);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:03 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/03/09 14:38:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) dest;
	ptr2 = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	while (n-- > 0)
	{
		*(ptr1++) = *(ptr2++);
	}
	return (dest);
}	

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:10:04 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/14 15:07:55 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *str)
{
	int			count;
	const char	*nullstr;

	nullstr = "(null)";
	count = 0;
	if (str == NULL)
	{
		while (*nullstr != '\0')
		{
			count += ft_putchar(*nullstr);
			nullstr++;
		}
		return (count);
	}
	while (*str != '\0')
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

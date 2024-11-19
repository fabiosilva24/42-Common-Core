/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:10:04 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/06/19 18:34:00 by fsilva-p         ###   ########.fr       */
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

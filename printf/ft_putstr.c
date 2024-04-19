/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:10:04 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/05 17:10:16 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(const char *str)
{	
	int count;
	const char *nullStr;
	
	nullStr = "(null)";

	count = 0;

	if (str == NULL)
		{	
			while (*nullStr != '\0')
		{
			count += ft_putchar(*nullStr);
			nullStr++;
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

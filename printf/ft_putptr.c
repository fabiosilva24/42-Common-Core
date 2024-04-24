/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:05:27 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/24 16:06:24 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_deci_to_hexa(ptr);
	return (count);
}

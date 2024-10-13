/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:10:41 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/13 23:27:18 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	count += ft_putchar('0' + n % 10);
	return (count);
}

int ft_putnbr_with_plus(int n, int plus_flag)
{
	int count;

	count = 0;
	if (n >= 0 && plus_flag)
		count += ft_putchar('+');
	count += ft_putnbr(n);
	return count;
}

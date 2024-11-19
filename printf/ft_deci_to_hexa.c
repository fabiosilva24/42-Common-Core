/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:53:11 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/13 23:46:40 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_deci_to_hexa(unsigned long n)
{
	char			hexa;
	int				count;

	count = 0;
	if (n >= 16)
	{
		count += ft_deci_to_hexa(n / 16);
	}
	hexa = "0123456789abcdef"[n % 16];
	write (1, &hexa, 1);
	count++;
	return (count);
}

int	ft_deci_to_hexa_with_prefix(unsigned long n, int uppercase)
{
	int		count;
	char	*prefix;
	int		hash_flag;

	count = 0;
	if (hash_flag && n != 0)
	{
		if (uppercase)
			prefix = "0X";
		else
			prefix = "0x";
		count += ft_putstr(prefix);
	}
	if (uppercase)
		count += ft_deci_to_hexauppercase(n);
	else
		count += ft_deci_to_hexa(n);
	return (count);
}

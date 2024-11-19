/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_to_hexauppercase.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:54:10 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/24 16:25:20 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_deci_to_hexauppercase(unsigned long n)
{
	char				hexa;
	int					count;

	count = 0;
	if (n >= 16)
	{
		count += ft_deci_to_hexauppercase(n / 16);
	}
	hexa = "0123456789ABCDEF"[n % 16];
	write (1, &hexa, 1);
	count++;
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:53:11 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/06/19 18:32:14 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

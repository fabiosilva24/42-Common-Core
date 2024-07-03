/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:31:45 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/07/03 14:30:56 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	if (str == NULL)
	{
		return (0);
	}
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (ft_isdigit(*str))
		i = (i * 10) + (*str++ - '0');
	return (i * sign);
}

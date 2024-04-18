/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:42:01 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/10 11:42:21 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_itoa_len(long nmbr)
{
	size_t	len;

	len = 0;
	if (nmbr == 0)
		return (1);
	if (nmbr < 0)
	{
		len++;
		nmbr = -nmbr;
	}
	while (nmbr > 0)
	{
		len++;
		nmbr /= 10;
	}
	return (len);
}

static char	*ft_nmbr_to_str(long nmbr, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nmbr < 0)
	{
		str[0] = '-';
		nmbr = -nmbr;
	}

	while (len > 0)
	{
		str[--len] = (nmbr % 10) + '0';
		nmbr /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	nmbr;
	size_t	len;
	char	*str;

	nmbr = n;
	len = ft_itoa_len(nmbr);
	str = 0;
	str = ft_nmbr_to_str(nmbr, len);
	if (!str)
		return (NULL);
	return (str);
}	

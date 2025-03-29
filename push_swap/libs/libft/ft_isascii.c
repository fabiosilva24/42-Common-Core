/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:19:52 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/23 21:20:20 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*#include <stdio.h>
int main()
{
	char c = '\127';
	if (ft_isascii(c))
{
	printf("%c is in the ascii table.\n", c);
} else{
	printf("%c is not in the ascii table.\n", c);
}
	return 0;
}*/

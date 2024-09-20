/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:14:38 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/20 17:41:24 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int arg)
{
	return (arg >= 32 && arg <= 126);
}

/*#include <stdio.h>
int main(void)
{
	char c = 'Q';
	printf("%c is printable(): %d\n", c, ft_isprint(c));
	
	c = '0';
	printf("\n%c is not printable(): %d\n", c, ft_isprint(c));
	
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:28:39 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/21 18:21:46 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int arg)
{
	if (arg <= '9' && arg >= '0')
		return (1);
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	int result;
	result = ft_isdigit('a');
	printf("Test: 'a' Result: %d", result);
	result = ft_isdigit('9');
        printf("\nTest: '9' Result: %d", result);

	return (0);
	
}*/

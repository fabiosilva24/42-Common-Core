/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:29:05 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/10 12:31:24 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	unsigned_length(unsigned int num)
{
	int length;
	
	length = 1;
	while (num /= 10)
		length++;
		return length;
}

void	ft_putunsigned(unsigned int num)
{
	if (num >= 10)
	{
		ft_putunsigned(num / 10);
	}
	char digit;
	
	digit = num % 10 + '0';
	write(1, &digit, 1);
}

int main() 
{
    unsigned int num = 12345;
    ft_printf("Number: %u\n", num);
    ft_printf("Length: %d\n", unsigned_length(num));
    ft_printf("Printing digits: ");
    ft_putunsigned(num);
    ft_printf("\n");
    return 0;
}

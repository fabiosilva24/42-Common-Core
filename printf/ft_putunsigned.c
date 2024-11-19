/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:29:05 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/24 16:27:19 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_length(unsigned int num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

int	ft_putunsigned(unsigned int num)
{
	int		count;
	char	digit;

	count = 0;
	if (num >= 10)
	{
		count += ft_putunsigned(num / 10);
	}
	digit = num % 10 + '0';
	count += write(1, &digit, 1);
	return (count);
}

/*int main() 
{
    unsigned int num = 12345;
    ft_printf("Number: %u\n", num);
    ft_printf("Length: %d\n", unsigned_length(num));
    ft_printf("Printing digits: ");
    ft_putunsigned(num);
    ft_printf("\n");
    return 0;
}*/

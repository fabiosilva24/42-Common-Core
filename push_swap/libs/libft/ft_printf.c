/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:47:24 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/14 15:07:55 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list args, const char *format)
{
	int	print_length;

	print_length = 0;
	if (*format == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		print_length += ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		print_length += ft_putnbr(va_arg(args, int));
	else if (*format == 'p')
		print_length += ft_putptr(va_arg(args, unsigned long long));
	else if (*format == 'u')
		print_length += ft_putunsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		print_length += ft_deci_to_hexa(va_arg(args, unsigned int));
	else if (*format == 'X')
		print_length += ft_deci_to_hexauppercase(va_arg(args, unsigned int));
	else if (*format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_formats(args, &format[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

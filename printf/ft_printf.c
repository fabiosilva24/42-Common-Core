/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:47:24 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/13 23:37:13 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flags(const char **format)
{
	int	flags;

	flags = 0;
	while (**format == '#' || **format == '+')
	{
		if (**format == '#')
			flags |= 1;
		else
			flags |= 2;
		(*format)++;
	}
	return (flags);
}

static int	ft_formats(va_list args, const char **format)
{
	int	print_length;
	int	flags;

	print_length = 0;
	flags = handle_flags(format);
	if (**format == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (**format == 's')
		print_length += ft_putstr(va_arg(args, char *));
	else if (**format == 'd' || **format == 'i')
		print_length += ft_putnbr_with_plus(va_arg(args, int), flags & 2);
	else if (**format == 'p')
		print_length += ft_putptr(va_arg(args, unsigned long long));
	else if (**format == 'u')
		print_length += ft_putunsigned(va_arg(args, unsigned int));
	else if (**format == 'x' || **format == 'X')
		print_length += ft_deci_to_hexa_with_prefix(va_arg(args, unsigned int),
				**format == 'X', flags & 1);
	else if (**format == '%')
		print_length += ft_printpercent(;
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
			i++;
			print_length += ft_formats(args, &format + i);
			while (format[i] && !ft_strchr("cspdiuxX%", format[i]))
				i++;
		}
		else
			print_length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

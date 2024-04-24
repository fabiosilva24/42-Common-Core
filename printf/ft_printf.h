/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:07:19 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/24 16:16:02 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h> //variadic stuff
# include <unistd.h> //write
# include <stddef.h>
# include <stdlib.h> //malloc free
# include <limits.h> //INT_MAX

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int num);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memset(void *str, int c, size_t n);
int		ft_putptr(unsigned long long ptr);
int		ft_deci_to_hexa(unsigned long n);
char	*ft_itoa(int n);
int		ft_deci_to_hexauppercase(unsigned long n);
int		ft_printpercent(void);

#endif

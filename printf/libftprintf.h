#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int ft_printf(const char *format, ...);
int ft_putchar(int c);
void	ft_putstr(const char *str);
void	ft_putnbr(int n);
int	ft_putunsigned(unsigned int num);
char	*ft_itoa(int n);








#endif

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h> //variadic stuff
# include <unistd.h> //write
# include <stddef.h>
# include <stdlib.h> //malloc free
# include <limits.h> //INT_MAX

int ft_printf(const char *format, ...);
int ft_putchar(int c);
void	ft_putstr(const char *str);
void	ft_putnbr(int n);
void	ft_putunsigned(unsigned int num);
char	*ft_itoa(int n);
void    *ft_calloc(size_t nitems, size_t size);
void	*ft_memset(void *str, int c, size_t n);









#endif

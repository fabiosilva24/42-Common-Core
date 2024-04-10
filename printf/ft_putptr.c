#include "libftprintf.h"

void	ft_putptr(void *ptr)
{
	char *strptr;
	
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return ;
	}
	
	ft_putstr("0x");
	ft_printhexa((unsigned long)ptr);
}	

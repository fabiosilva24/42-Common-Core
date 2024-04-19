#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	count;
	
	count = 0;
	if (ptr == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	
	count += ft_putstr("0x");
	count += ft_deci_to_hexa(ptr);

	return (count);
}	

#include "ft_printf.h"

int ft_deci_to_hexa(long n)
{
	char hexa;

	int count;

	count = 0;

<<<<<<< HEAD
	if (n >= 16)
	{
		count += ft_deci_to_hexa(n / 16);
=======
	if (n <= 0)
	{	
		return (0);
>>>>>>> refs/remotes/origin/main
	}

	hexa = "0123456789abcdef"[n % 16];

	write (1, &hexa, 1);
	count++;

	return count;
}

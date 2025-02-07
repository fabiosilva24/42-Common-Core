#include "libft.h"

int ft_isspace(int argument)
{
	if (argument == ' ' || argument == '\t' || argument == '\n'
		|| argument == '\v' || argument == '\f' || argument == '\r')
		return (1);
	return (0);
}
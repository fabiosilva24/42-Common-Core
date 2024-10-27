#include "../include/push_swap.h"
#include <stdio.h>

static long ft_atol(const char *str)   //ascii to long
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || *str >= 9 && *str <= 13)
            str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (sign * result);
}

/*int main(void)
{
    const char *str = "1234567891111111111111111";
    long test = ft_atol(str);

    printf("converted number: %ld\n", test);
}/*
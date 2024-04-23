#include "ft_printf.h"

int ft_deci_to_hexauppercase(unsigned long long n)
{
        char hexa;

        int count;

        count = 0;

        if (n >= 16)
        {
                count += ft_deci_to_hexauppercase(n / 16);
        }

        hexa = "0123456789ABCDEF"[n % 16];

        write (1, &hexa, 1);
        count++;

        return count;
}


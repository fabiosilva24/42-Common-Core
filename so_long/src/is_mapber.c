#include "../include/so_long.h"

int is_mapber(char *filename)
{
    int len;

    if (!filename)
    {
        ft_printf("Filename is NULL\n");
        return (0);
    }

    len = ft_strlen(filename);
    ft_printf("Filename: %s, Length: %d\n", filename, len);

    if (len < 4)
    {
        ft_printf("Filename is too short\n");
        return (0);
    }

    if (ft_strncmp(filename + len - 4, ".ber", 4) == 0)
    {
        ft_printf("Filename has .ber extension\n");
        return (1);
    }

    ft_printf("Filename does not have .ber extension\n");
    return (0);
}
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
    if (filename[len - 3] == 'b' &&
            filename[len - 2] == 'e' &&
            filename[len - 1] == 'r')
    {
        return (1);
    }
    ft_printf("Filename does not have .ber extension\n");
    return (0);
}

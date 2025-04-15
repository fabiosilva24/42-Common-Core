#include "../includes/cub3d.h"

int is_mapber(char *filename)
{
    int len;

    if (!filename)
    {
        ft_printf("Filename is NULL\n");
        return (0);
    }
    len = ft_strlen(filename);
    if (filename[len - 3] == 'c' &&
            filename[len - 2] == 'u' &&
            filename[len - 1] == 'b')
    {
        return (1);
    }
    ft_printf("Filename does not have .cub extension\n");
    return (0);
}

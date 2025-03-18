#include "../include/so_long.h"

void is_theremorethan1player(t_game *game)
{
    if (game->player < 1)
    {
        ft_printf("more than 1 player found\n");
        return ;
    }
}
#include "../include/so_long.h"

void draw_move_count(t_game *game)
{
    char *move_count_str;

    move_count_str = ft_itoa(game->move_count);
    if (!move_count_str)
    {
        ft_printf("Error: failled to allocate memory\n");
        return ;
    }
    mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10,  0xFFFFFF, move_count_str);
    free(move_count_str);
}
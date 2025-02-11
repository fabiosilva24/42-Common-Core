#include "../include/so_long.h"

void free_textures(t_game *game)
{
    if (game->wall_img)
    {
        mlx_destroy_image(game->mlx_ptr, game->wall_img);
        game->wall_img = NULL;
    }
    if (game->player_img)
    {
        mlx_destroy_image(game->mlx_ptr, game->player_img);
        game->player_img = NULL;
    }
    if (game->exit_img)
    {
        mlx_destroy_image(game->mlx_ptr, game->exit_img);
        game->exit_img = NULL;
    }
    if (game->collectible_img)
    {
        mlx_destroy_image(game->mlx_ptr, game->collectible_img);
        game->collectible_img = NULL;
    }
    if (game->floor_img)
    {
        mlx_destroy_image(game->mlx_ptr, game->floor_img);
        game->floor_img = NULL;
    }
}

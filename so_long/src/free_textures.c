#include "../include/so_long.h"

void free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall_img);
	mlx_destroy_image(game->mlx_ptr, game->player_img);
	mlx_destroy_image(game->mlx_ptr, game->exit_img);
	mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	mlx_destroy_image(game->mlx_ptr, game->floor_img);
}

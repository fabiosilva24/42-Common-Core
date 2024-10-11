#include "../include/so_long.h"

void initialize_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		write(2, "Error initializing MLX\n", 23);
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, 512, 256, "So Long");	
	if (!game->win_ptr)
	{
		write(2, "Error creating the window\n", 23);
		exit(EXIT_FAILURE);
	}

}

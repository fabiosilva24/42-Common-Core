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

	game->background_image = mlx_xpm_file_to_image(game->mlx_ptr, "../assets/sprites/background/B1013-6.xpm", &game->bg_width, &game->bg_height);
	if (!game->background_image)
	{
		write (2, "Error loading background image\n", 31);
		exit(EXIT_FAILURE);
	}

	game->player.x = 100;
	game->player.y = 100;

}

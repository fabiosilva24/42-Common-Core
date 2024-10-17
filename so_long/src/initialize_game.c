#include "../include/so_long.h"

void initialize_game(t_game *game, char *file)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error initializing MLX\n");
		exit(EXIT_FAILURE);
	}
	game->map_file = file;
	if (!get_map_dimensions(game, &game->map_width, &game->map_height))
	{
		ft_printf("Error: failed to get the map dimensions\n");
		exit(EXIT_FAILURE);
	}
	int window_width;
	int window_height;

	window_width = game->map_width * 24;
	window_height = game->map_height * 24;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window_width, window_height, "So Long");
	if (!game->win_ptr)
	{
		ft_printf("Error creating the window\n");
		exit(EXIT_FAILURE);
	}
	load_images(game);
	int i = 0, j = 0;
	while(i  < game->map_width)
	{
		while (j < game->map_height)
		{
			if (game->map[i][j] == 'P')
			{	
				ft_printf("%c",game->map[i][j]);
				game->player.x = i;
				game->player.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

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

	if (!map_draw(game))
	{
		ft_printf("Error: Failed to load the map\n");
		exit(EXIT_FAILURE);
	}

	game->move_count = 0;

	game->total_collectibles = 0;
	game->collected_collectibles = 0;

	// Count total collectibles
	for (int y = 0; y < game->map_height; y++)
	{
		for (int x = 0; x < game->map_width; x++)
		{
			if (game->map[y][x] == 'C')
			{
				game->total_collectibles++;
			}
		}
	}

	ft_printf("Total collectibles in the map: %d\n", game->total_collectibles);

	// Find player position
	int player_found = 0;
	for (int i = 0; i < game->map_height; i++)
	{
		for (int j = 0; j < game->map_width; j++)
		{
			if (game->map[i][j] == 'P')
			{   
				game->player.x = j;
				game->player.y = i;
				ft_printf("Player initial position: x=%d, y=%d\n", j, i);
				player_found = 1;
				break;
			}
		}
		if (player_found) break;
	}

	if (!player_found)
	{
		ft_printf("Error: Player not found in the map\n");
		exit(EXIT_FAILURE);
	}

	ft_printf("Setting up render loop\n");
	mlx_loop_hook(game->mlx_ptr, render_game, game);
	ft_printf("Render loop set up complete\n");

	ft_printf("Setting up key hook\n");
	mlx_key_hook(game->win_ptr, handle_keypress, game);
	ft_printf("Key hook set up complete\n");

	game->should_end = 0;
}

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Usage : ./so_long map\n");
		return (0);
	}

	ft_printf("Initializing game\n");
	initialize_game(&game, argv[1]);
	ft_printf("Game initialization complete\n");

	if (!map_draw(&game) || !is_rectangle(&game) || !is_closed_by_walls(&game))
	{
		cleanup_game(&game);
		ft_printf("Invalid map\n");
		return (0);
	}

	ft_printf("Setting up input handling\n");
	handle_input(&game);
	ft_printf("Input handling set up\n");

	ft_printf("Map width: %d, Map height: %d\n", game.map_width, game.map_height);
	ft_printf("Starting game loop\n");
	mlx_loop(game.mlx_ptr);

	if (game.should_end)
	{
		ft_printf("Game ended\n");
	}

	cleanup_game(&game);
	return (0);
}

int game_loop(t_game *game)
{
	render_game(game);
	
	if (game->should_end)
	{
		ft_printf("Game is ending\n");
		mlx_loop_end(game->mlx_ptr);
	}
	
	return (0);
}

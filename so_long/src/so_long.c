#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Usage : ./so_long map\n");
		return (0);
	}

	initialize_game(&game);
	if (!map_draw(&game, argv[1]) || !is_rectangle(&game) || !is_closed_by_walls(&game))
	{
		cleanup_game(&game);
		ft_printf("Invalid map\n");
	}

	handle_input(&game);

	mlx_loop(game.mlx_ptr);

	cleanup_game(&game);
	return (0);
}

#include "../include/so_long.h"

int handle_window_close(t_game *game)
{
	ft_printf("Window close button clicked, exiting game\n");
	game->should_end = 1;
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

void handle_input(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L<<0, handle_keypress, game);  // Key press event
	mlx_hook(game->win_ptr, 17, 1L<<17, handle_window_close, game);  // Window close event
}

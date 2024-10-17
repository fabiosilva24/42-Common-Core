#include "../include/so_long.h"

void handle_input(t_game *game)
{
	  mlx_hook(game->win_ptr, 2, 1L<<0,          handle_keypress, game);  // Key press event

}

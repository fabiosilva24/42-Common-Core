#include "../include/so_long.h"

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	game->player.y -= 1;
	else if (keycode == KEY_A)
	game->player.x -= 1;
	else if (keycode == KEY_S)
	game->player.y += 1;
	else if (keycode == KEY_D)
	game->player.x += 1;
	else if (keycode == KEY_ESC)
	{
			cleanup_game(game);
			exit(0);
	}

	render_game(game);
	
	return (0);
}

#include "../include/so_long.h"

int handle_keypress(int keycode, t_game *game)
{
	int new_x = game->player.x;
	int new_y = game->player.y;

	if (keycode == KEY_W)
	{
	new_y -= 1;
	}
	else if (keycode == KEY_A)
	new_y -= 1;
	else if (keycode == KEY_S)
	new_x += 1;
	else if (keycode == KEY_D)
	new_x += 1;
	else if (keycode == KEY_ESC)
	{
			mlx_loop_end(game->mlx_ptr);
			cleanup_game(game);
	}

	handle_player_move(game, &game->player, new_x, new_y);
	render_game(game);
	
	return (0);
}
void handle_player_move(t_game *game, t_player *player, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		t_player new_position = {new_x, new_y, player->player};
		flood_fill(game, (t_player){game->map_width, game->map_height, player->player}, new_position, game->map[new_y][new_x]);
		player->x = new_x;
		player->y = new_y;
		game->move_count++;
		ft_printf("Number of moves: %d\n", game->move_count);

		check_collectible(game, player);
		check_exit(game, player);
	}
	else
	{
		ft_printf("Blocked by walls\n");
	}
}


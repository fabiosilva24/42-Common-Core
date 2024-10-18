#include "../include/so_long.h"

int handle_keypress(int keycode, t_game *game)
{
	ft_printf("Key pressed: %d\n", keycode);
	int new_x = game->player.x;
	int new_y = game->player.y;

	if (keycode == KEY_W)
		new_y -= 1;
	else if (keycode == KEY_A)
		new_x -= 1;
	else if (keycode == KEY_S)
		new_y += 1;
	else if (keycode == KEY_D)
		new_x += 1;
	else if (keycode == KEY_ESC)
	{
		ft_printf("ESC key pressed, exiting game\n");
		mlx_loop_end(game->mlx_ptr);
		cleanup_game(game);
		exit(0);
	}
	handle_player_move(game, &game->player, new_x, new_y);
	render_game(game);
	if (game->should_end)
		mlx_loop_end(game->mlx_ptr);
	return (0);
}

void handle_player_move(t_game *game, t_player *player, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width || new_y < 0 || new_y >= game->map_height)
	{
		ft_printf("Error: Attempted move out of map bounds\n");
		return;
	}
	if (game->map[new_y][new_x] != '1')
	{
		game->map[player->y][player->x] = '0';  // Set old position to empty
		player->x = new_x;
		player->y = new_y;
		game->map[new_y][new_x] = 'P';  // Set new position to player
		game->move_count++;
		ft_printf("Number of moves: %d\n", game->move_count);
		check_collectible(game, player);
		check_exit(game, player);  // Call this after updating player position
	}
	else
	{
		ft_printf("Blocked by walls\n");
	}
}

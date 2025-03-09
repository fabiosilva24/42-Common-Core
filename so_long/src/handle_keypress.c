/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:50:48 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/03/09 05:48:18 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keypress(int keycode, t_game *game, int new_x, int new_y)
{
	ft_printf("Key pressed: %d\n", keycode);
	new_x = game->player.x;
	new_y = game->player.y;
	if (keycode == KEY_W || keycode == UP_ARROW)
	{
		new_y -= 1;
		game->player_img = game->up_img;
	}
	else if (keycode == KEY_A || keycode == LEFT_ARROW)
	{
		new_x -= 1;
		game->player_img = game->left_img;
	}
	else if (keycode == KEY_S || keycode == DOWN_ARROW)
	{
		new_y += 1;
		game->player_img = game->down_img;
	}
	else if (keycode == KEY_D || keycode == RIGHT_ARROW)
	{
		new_x += 1;
		game->player_img = game->right_img;
	}
	else if (keycode == KEY_ESC)
	{
		ft_printf("ESC key pressed, exiting game\n");
		game->should_end = 1;
		mlx_loop_end(game->mlx_ptr);
		return(0);
	}
	handle_player_move(game, &game->player, new_x, new_y);
	render_game(game);
	if (game->should_end)
		mlx_loop_end(game->mlx_ptr);
	return (0);
}

void	handle_player_move(t_game *game, t_player *player, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width || new_y < 0 || \
		new_y >= game->map_height)
	{
		ft_printf("Error: Attempted move out of map bounds\n");
		return ;
	}
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->collected_collectibles++;
			game->map[player->y][player->x] = '0';
		}
		if (game->map[player->y][player->x] != 'E')
			game->map[player->y][player->x] = '0';
		player->x = new_x;
		player->y = new_y;
		if (game->map[new_y][new_x] != 'E')
			game->map[new_y][new_x] = 'P';
		update_movecount(game);
		check_collectible(game, player);
		check_exit(game, player);
	}
	else
		ft_printf("Blocked by walls\n");
}

void	update_movecount(t_game *game)
{
	game->move_count++;
	ft_printf("Number of moves: %d\n", game->move_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:00:07 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/15 14:12:25 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_game *game, t_player size, t_player cur, char to_fill)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| map[cur.y][cur.x] != to_fill)
		return ;
	game->map[cur.y][cur.x] = 'P';
	flood_fill(game->map, size, (t_player){cur.x - 1, cur.y}, to_fill);
	flood_fill(game->map, size, (t_player){cur.x + 1, cur.y}, to_fill);
	flood_fill(game->map, size, (t_player){cur.x, cur.y - 1}, to_fill);
	flood_fill(game->map, size, (t_player){cur.x, cur.y + 1}, to_fill);
}

int	is_valid_move(t_game *game, t_player next)
{
	char	next_position;

	if (next.x < 0 || next.x >= game->numb_rows || next.y < 0
		|| next.y >= game->numb_rows)
		return (0);
	next_position = game->map[next.y][next.x];
	return (next_position == '0' || next_position == 'C'
		|| next_position == 'E');
}

t_player	move_player(t_game *game)
{
	t_player	next;
	int			move_x;
	int			move_y;

	move_x = 0;
	move_y = 0;
	next.x = game->player.x + move_x;
	next.y = game->player.y + move_y;
	if (is_valid_move(game, next))
	{
		game->map[game->player.y][game->player.x] = '0';
		game->map[next.y][next.x] = 'P';
		game->player = next;
	}
	return (game->player);
}

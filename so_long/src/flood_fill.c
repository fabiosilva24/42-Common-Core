/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:00:07 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/14 19:17:33 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_game *game, t_player size, t_player cur, char to_fill)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| game->map[cur.y][cur.x] != to_fill)
		return ;
	game->map[cur.y][cur.x] = 'P';
	flood_fill(map, size, (t_player){cur.x - 1, cur.y}, to_fill);
	flood_fill(map, size, (t_player){cur.x + 1, cur.y}, to_fill);
	flood_fill(map, size, (t_player){cur.x, cur.y - 1}, to_fill);
	flood_fill(map, size, (t_player){cur.x, cur.y + 1}, to_fill);
}

int	is_valid_move(t_game *game, t_player size, t_player current, t_player next)
{
	char	next_position;

	if (next.x < 0 || next.x >= size.x || next.y < 0 || next.y >= size.y)
		return (0);
	next_position = game->map[next.y][next.x];
	return (next_position == '0' || next_position == 'C'
		|| next_position == 'E');
}

t_player	move_player(t_game *game, t_player size, t_player current)
{
	t_player	next;
	int move_x;
	int move_y;

	next.x = current.x + move_x;
	next.y = current.y + move_y;
	if (is_valid_move(game->map, size, current, next))
	{
		game->map[current.y][current.x] = '0';
		game->map[next.y][next.x] = 'P';
		return (next);
	}
	return (current);
}

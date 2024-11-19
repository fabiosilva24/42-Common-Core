/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:49:08 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/18 23:47:48 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
	{
		ft_printf("Error: Attempted to draw tile out of bounds");
		return ;
	}
	if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->floor_img, x * 24, y * 24);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_img, x * 24, y * 24);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall_img, x * 24, y * 24);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit_img, x * 24, y * 24);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collectible_img, x * 24, y * 24);
}

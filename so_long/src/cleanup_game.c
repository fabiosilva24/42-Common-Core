/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:39:51 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/03/04 19:24:37 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_game *game)
{
	int i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}
void	cleanup_game(t_game *game)
{
	free_map(game);
	if (game->mlx_ptr)
	{
		if (game->player_img)
			mlx_destroy_image(game->mlx_ptr, game->player_img);
		if (game->floor_img)
			mlx_destroy_image(game->mlx_ptr, game->floor_img);
		if (game->wall_img)
			mlx_destroy_image(game->mlx_ptr, game->wall_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx_ptr, game->exit_img);
		if (game->collectible_img)
			mlx_destroy_image(game->mlx_ptr, game->collectible_img);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

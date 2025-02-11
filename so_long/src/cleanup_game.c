/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:39:51 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/02/11 16:07:53 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cleanup_game(t_game *game)
{
	if (game->win_ptr)
	{
		mlx_destroy_display(game->win_ptr);
		free(game->win_ptr);
		game->win_ptr = NULL;
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	free_map(game);
	free_textures(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:39:51 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/03/09 05:37:05 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cleanup_game(t_game *game)
{
	cleanup_textures(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
}
void cleanup_textures(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->up_img);
	mlx_destroy_image(game->mlx_ptr, game->down_img);
	mlx_destroy_image(game->mlx_ptr, game->right_img);
	mlx_destroy_image(game->mlx_ptr, game->left_img);
	mlx_destroy_image(game->mlx_ptr, game->player_img);
	mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_img);
	mlx_destroy_image(game->mlx_ptr, game->floor_img);
}

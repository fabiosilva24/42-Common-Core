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

void cleanup_game(t_game *game)
{
    int i;
    
    // Free map memory
    if (game->map)
    {
        i = 0;
        while (i < game->map_height)
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
        game->map = NULL;
    }
    
    // Free images
    if (game->wall_img)
        mlx_destroy_image(game->mlx_ptr, game->wall_img);
    if (game->player_img)
        mlx_destroy_image(game->mlx_ptr, game->player_img);
    if (game->collectible_img)
        mlx_destroy_image(game->mlx_ptr, game->collectible_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx_ptr, game->exit_img);
    if (game->floor_img)
        mlx_destroy_image(game->mlx_ptr, game->floor_img);
        
    // Destroy window and MLX connection
    if (game->win_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    if (game->mlx_ptr)
        mlx_destroy_display(game->mlx_ptr);
    free(game->mlx_ptr);
}

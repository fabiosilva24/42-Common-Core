/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:39:51 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/18 23:46:45 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cleanup_game(t_game *game)
{
	if (game->win_ptr)
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
}

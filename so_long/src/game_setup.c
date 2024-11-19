/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabiosilva <fabiosilva@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:29:02 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/20 22:46:31 by fabiosilva       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_game_state(t_game *game)
{
	game->move_count = 0;
	game->total_collectibles = 0;
	game->collected_collectibles = 0;
	game->should_end = 0;
}

static void	setup_mlx_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx_ptr, render_game, game);
	mlx_key_hook(game->win_ptr, handle_keypress, game);
}

void	setup_game(t_game *game)
{
	load_images(game);
	map_dont_draw(game);
	map_draw(game);
	init_game_state(game);
	count_collectibles(game);
	find_player_position(game);
	setup_mlx_hooks(game);
}

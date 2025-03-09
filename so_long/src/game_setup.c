/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:29:02 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/03/09 06:08:40 by fsilva-p         ###   ########.fr       */
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
    
    // Use mlx_hook instead of mlx_key_hook for more control
    // 2 is the KeyPress event code, 1L<<0 is the KeyPressMask
    mlx_hook(game->win_ptr, 2, 1L<<0, handle_keypress, game);
    
    // Optional: Add hook for window close event (X button)
    mlx_hook(game->win_ptr, 17, 0, handle_window_close, game);
}

void	setup_game(t_game *game)
{
	load_images(game);
	load_images2(game);
	map_dont_draw(game);
	map_draw(game);
	init_game_state(game);
	count_collectibles(game);
	find_player_position(game);
	setup_mlx_hooks(game);
}

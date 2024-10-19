/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:04:23 by fabiosilva        #+#    #+#             */
/*   Updated: 2024/10/20 01:32:06 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error initializing MLX\n");
		exit(EXIT_FAILURE);
	}
}

static void init_window(t_game *game, int width, int height)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "So Long");
	if (!game->win_ptr)
	{
		ft_printf("Error creating the window\n");
		exit(EXIT_FAILURE);
	}
}

void initialize_game(t_game *game, char *file)
{
	int window_width;
	int window_height;

	init_mlx(game);
	game->map_file = file;
	if (!get_map_dimensions(game, &game->map_width, &game->map_height))
	{
		ft_printf("Error: failed to get the map dimensions\n");
		exit(EXIT_FAILURE);
	}
	window_width = game->map_width * 24;
	window_height = game->map_height * 24;
	init_window(game, window_width, window_height);
	setup_game(game);
}

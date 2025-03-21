/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:46:41 by fabiosilva        #+#    #+#             */
/*   Updated: 2025/03/09 16:27:34 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage : ./so_long map\n");
		return (0);
	}
	if (!is_mapber(argv[1]))
		return (0);
	initialize_game(&game, argv[1]);
	if (!map_draw(&game))
	{
		cleanup_game(&game);
		ft_printf("Invalid map\n");
		return (0);
	}
	handle_input(&game);
	mlx_loop(game.mlx_ptr);
	if (game.should_end)
	{
		ft_printf("Game ended\n");
	}
	cleanup_game(&game);
	return (0);
}

int	game_loop(t_game *game)
{
	render_game(game);
	if (game->should_end)
	{
		ft_printf("Game is ending\n");
		mlx_loop_end(game->mlx_ptr);
	}
	return (0);
}

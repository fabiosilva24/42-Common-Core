/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:49:50 by fabiosilva        #+#    #+#             */
/*   Updated: 2025/03/04 19:01:44 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_game(void *param)
{
	t_game	*game;
	int		y;
	int		x;
	static int						frame_count;

	game = (t_game *)param;
	frame_count = 0;
	frame_count++;
	//mlx_clear_window(game->mlx_ptr, game->win_ptr);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	draw_move_count(game);
	return (0);
}

void	load_images(t_game *game)
{
	int	height;
	int	width;

	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/floor.xpm", &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/player.xpm", &width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/wall.xpm", &width, &height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/collectible.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/exit.xpm", &width, &height);
	game->should_end = 0;
	if (!game->floor_img)
		ft_printf("Error: failed to load floor image\n");
	if (!game->player_img)
		ft_printf("Error: failed  to load player image\n");
	if (!game->wall_img)
		ft_printf("Error: failed to load wall image\n");
	if (!game->exit_img)
		ft_printf("Error: failed to load exit image\n");
	if (!game->collectible_img)
		ft_printf("Error: failed to load collectible image\n");
}

int	render_game_wrapper(void *param)
{
	return (render_game((t_game *)param));
}

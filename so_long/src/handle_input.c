/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabiosilva <fabiosilva@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:49:58 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/20 01:03:30 by fabiosilva       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_window_close(t_game *game)
{
	ft_printf("Window close button clicked, exiting game\n");
	game->should_end = 1;
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

void	handle_input(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, handle_window_close, game);
}

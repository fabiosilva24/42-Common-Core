/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:13:09 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/18 18:40:35 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_collectible(t_game *game, t_player *player)
{
	if (game->map[player->y][player->x] == 'C')
	{
		game->collected_collectibles++;
		game->map[player->y][player->x] = '0';
		ft_printf("Collectible found! Total collected: %d / %d\n",
			game->collected_collectibles, game->total_collectibles);
	}
	if (game->collected_collectibles == game->total_collectibles)
		game->exit_open = 1;
}

void	check_exit(t_game *game, t_player *player)
{
	if (game->map[player->y][player->x] == 'E'
			&& game->collected_collectibles < game->total_collectibles)
	{
		ft_printf("You haven't collected all items yet!\n");
		return ;
	}
	if (game->map[player->y][player->x] == 'E'
			&& game->collected_collectibles == game->total_collectibles)
	{
		ft_printf("Congratulations You Won \n:D\n");
		game->should_end = 1;
	}
}

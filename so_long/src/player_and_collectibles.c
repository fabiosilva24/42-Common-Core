/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_and_collectibles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:29:35 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/12/20 19:17:54 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void check_if_c_is_reachable(t_game *game)
{
	int x;
	int y;
	char **temp;

	temp = ft_calloc(game->map_height + 1, sizeof(char *))
	y = -1;
	while (++y < game->map_height)
		temp[y] = ft_strdup(game->map[y]);
	flood_fill(temp, game->player.y, game->player.x);
	y = -1;
	while (++y < game->map_height)
	{
		x = - 1;
		while (++x < game->map_width)
			if (temp[y][x] == 'C')
			{
				ft_printf("Error\nCollectible not reachable\n");
				free_temp(temp, game->map_height);
				exit(EXIT_FAILURE);
			}
	}
	free_temp(temp, game->map_height);
}
void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->total_collectibles++;
			x++;
		}
		y++;
	}
	ft_printf("Total collectibles in the map: %d\n", game->total_collectibles);
}

int count_players(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	game->player_count = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				if (game->player_count == 0)
				{
					game->player.x = j;
					game->player.y = i;
					game->player_found = 1;
				}
				game->player_count++;
			}
			j++;
		}
		i++;
	}
	return (game->player_count);
}

void	find_player_position(t_game *game)
{
	game->player_count = count_players(game);
	player_notfound(game);
	check_fordup(game);
}

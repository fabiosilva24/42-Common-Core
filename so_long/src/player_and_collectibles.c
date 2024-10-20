/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_and_collectibles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:29:35 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/20 01:29:37 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void count_collectibles(t_game *game)
{
    int x;
    int y;

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

void find_player_position(t_game *game)
{
    int i;
    int j;
    int player_found;

    i = 0;
    player_found = 0;
    while (i < game->map_height && !player_found)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == 'P')
            {
                game->player.x = j;
                game->player.y = i;
                player_found = 1;
                break;
            }
            j++;
        }
        i++;
    }
    if (!player_found)
    {
        ft_printf("Error: Player not found in the map\n");
        exit(EXIT_FAILURE);
    }
}

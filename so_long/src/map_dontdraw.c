/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dontdraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:11:34 by fabiosilva        #+#    #+#             */
/*   Updated: 2025/02/11 15:28:54 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_dont_draw(t_game *game)
{
	if (!map_draw(game))
	{
		cleanup_game(game);
		ft_printf("Error: Failed to load the map\n");
		exit(EXIT_FAILURE);
	}
}

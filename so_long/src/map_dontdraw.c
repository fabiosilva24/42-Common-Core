/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dontdraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabiosilva <fabiosilva@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:11:34 by fabiosilva        #+#    #+#             */
/*   Updated: 2024/10/20 01:15:23 by fabiosilva       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_dont_draw(t_game *game)
{
	if (!map_draw(game))
	{
		ft_printf("Error: Failed to load the map\n");
		exit(EXIT_FAILURE);
	}
}

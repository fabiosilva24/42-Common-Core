/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_notfound.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabiosilva <fabiosilva@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:13:49 by fabiosilva        #+#    #+#             */
/*   Updated: 2024/10/20 23:13:57 by fabiosilva       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_notfound(t_game *game)
{
	if (!game->player_found)
	{
		ft_printf("Error: player not found in the map\n");
		exit(EXIT_FAILURE);
	}
}

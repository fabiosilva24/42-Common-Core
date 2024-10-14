/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:23:51 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/14 16:28:32 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectangle(t_game *game)
{
	int	i;
	int	row_len;

	i = 1;
	row_len = ft_strlen(game->map[0]);
	while (i < game->numb_rows)
	{
		if (ft_strlen(game->map[i]) != row_len)
		{
			ft_printf("Map is not rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_top(t_game *game)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(game->map[0]);
	while (i < row_len)
	{
		if (game->map[0][i] != '1')
		{
			ft_printf("Map is not closed by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_bottom(t_game *game)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(game->map[0]);
	while (i < row_len)
	{
		if (game->map[game->numb_rows - 1][i] != '1')
		{
			ft_printf("map is not closed by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sides(t_game *game)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(game->map[0]);
	while (i < game->numb_rows)
	{
		if (game->map[i][0] != '1' || game->map[i][row_len - 1] != '1')
		{
			ft_printf("map is not closed by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_closed_by_walls(t_game *game)
{
	if (!check_top(game))
	{
		return (0);
	}
	if (!check_bottom(game))
	{
		return (0);
	}
	if (!check_sides(game))
	{
		return (0);
	}
	return (1);
}

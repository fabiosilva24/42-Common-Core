/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:23:51 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/18 23:59:10 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectangle(t_game *game)
{
	int	i;
	size_t	row_len;

	i = 1;
	row_len = ft_strlen(game->map[0]);
	while (i < game->numb_rows)
	{
		if (ft_strlen(game->map[i]) != row_len)
		{
			ft_printf("Error Map is not rectangle\n");
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
	row_len = ft_strlen(game->map[0]) - 1;
	while (i < row_len)
	{
		if (game->map[0][i] != '1')
		{
			ft_printf("Error Map is not closed by walls\n");
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
	row_len = ft_strlen(game->map[0]) - 1;
	while (i < row_len)
	{
		if (game->map[game->numb_rows - 1][i] != '1')
		{
			ft_printf("Error map is not closed by walls\n");
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
	row_len = ft_strlen(game->map[0]) - 1;
	while (i < game->numb_rows)
	{
		if (game->map[i][0] != '1' || game->map[i][row_len - 1] != '1')
		{
			ft_printf("Error map is not closed by walls\n");
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
		ft_printf("Top\n");
		return (0);
	}
	if (!check_bottom(game))
	{
		ft_printf("Bottom\n");
		return (0);
	}
	if (!check_sides(game))
	{
		ft_printf("sides\n");
		return (0);
	}
	return (1);
}

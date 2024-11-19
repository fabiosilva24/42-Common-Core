/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabiosilva <fabiosilva@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:54:07 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/20 00:58:55 by fabiosilva       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	read_map_lines(t_game *game, int fd, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			return (0);
		i++;
	}
	game->map[i] = 0;
	return (1);
}

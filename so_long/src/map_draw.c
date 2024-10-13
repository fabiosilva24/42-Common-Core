/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:37:46 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/13 01:54:19 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int count_lines(char *file)
{
	int fd;
	int count;
	char *line;

	fd = open_file(file);
	if (fd < 0)
		return (NULL);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return(count);
}

static int allocate_map(t_game *game, int line_count)
{
	game->map = malloc((line_count + 1) * sizeof(char*));
	if (game->map == NULL)
		return (0);
	return (1);
}

static void free_and_close(t_game *game, int fd)
{
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
	if (fd >= 0)
		close(fd);
}

static int read_map_lines(t_game *game, int fd, int line_count)
{
	int i;

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

int map_draw(t_game *game, char *file)
{
	int fd;
	int line_count;

	line_count = count_lines(file);
	if (line_count <= 0)
		return (0);
	if (!allocate_map(game, line_count))
		return (0);
	fd = open_file(file);
	if (fd < 0 || !read_map_lines(game, fd, line_count))
	{
		free_and_close(game, fd);
		return (0);
	}
	close(fd);
	return (1);
}

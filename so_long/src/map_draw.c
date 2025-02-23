/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:37:46 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/02/11 15:33:18 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_dimensions(t_game *game, int *width, int *height)
{
	int			fd;
	char		*line;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: could not open map file\n");
		return (0);
	}
	*height = 0;
	*width = 0;
	line = get_next_line(fd);
	if (line)
	{
		*width = ft_strlen(line) - 1;
	}
	while (line)
	{
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	allocate_map(t_game *game, int line_count)
{
	game->map = malloc((line_count + 1) * sizeof(char *));
	if (game->map == NULL)
	{
		ft_printf("Error: could not allocate memory for map\n");
		cleanup_game(game);
		return (0);
	}
	return (1);
}

void	free_and_close(t_game *game, int fd)
{
	if (game->map)
	{
		cleanup_game(game);
		game->map = NULL;
	}
	if (fd >= 0)
		close(fd);
}

int	map_draw(t_game *game)
{
	int	fd;
	int	line_count;

	line_count = count_lines(game->map_file);
	game->numb_rows = line_count;
	ft_printf("Number of rows: %d\n", line_count);
	if (line_count <= 0)
		return (0);
	if (!allocate_map(game, line_count))
	{
		cleanup_game(game);
		return (0);
	}
	fd = open(game->map_file, O_RDONLY);
	if (fd < 0 || !read_map_lines(game, fd, line_count))
	{
		cleanup_game(game);
		ft_printf("Error: Failed to open or read map file\n");
		free_and_close(game, fd);
		return (0);
	}
	close(fd);
	return (1);
}

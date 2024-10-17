/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:37:46 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/17 18:20:20 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int get_map_dimensions(t_game *game, int *width, int *height)
{
    int	fd;
    char	*line;

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
static int count_lines(char *file)
{
	int fd;
	int count;
	char *line;

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

void draw_tile(t_game *game, int x, int y)
{
	char tile = game->map[y][x];

	if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_ptr, game->floor_img, x * 24, y * 24);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_ptr, game->player_img, x * 24, y * 24);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_ptr, game->wall_img, x * 24, y * 24);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_ptr, game->exit_img, x * 24, y * 24);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_ptr, game->collectible_img, x * 24, y * 24);
}

int map_draw(t_game *game)
{
	int fd;
	int line_count;

	line_count = count_lines(game->map_file);
	game->numb_rows = line_count;
	if (line_count <= 0)
		return (0);
	if (!allocate_map(game, line_count))
		return (0);
	fd = open(game->map_file, O_RDONLY);
	if (fd < 0 || !read_map_lines(game, fd, line_count))
	{
		free_and_close(game, fd);
		return (0);
	}
	close(fd);
	return (1);
}

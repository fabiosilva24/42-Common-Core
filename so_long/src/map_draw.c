#include "../include/so_long.h"

char **map_draw(t_game *game, char *file)
{
	int fd;
	int i;

	i = 0;

	game->width_max = WIDTH_MAX;
	game->map = malloc((game->width_max + 1) * sizeof(char*));
	if (game->map == NULL)
		return (NULL);
	fd = open_file(file);
	if (fd < 0)
	{
		free(game->map);
		return (NULL);
	}
	while (i < game->width_max)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
	}
	game->map[i] = 0;
	close(fd);
	return (game->map);
}

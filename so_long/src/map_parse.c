//check for exit if its E
//exit only available when collecting all the coins
//mark how manny times you clicked on the buttons

#include "../include/so_long.h"

void check_collectible(t_game *game, t_player *player)
{
	game->total_collectibles = 0;
	game->collected_collectibles = 0;
	game-> exit_open = 0;


	if (game->map[player->y][player->x] == 'C')
	{
		game->collected_collectibles++;
		game->map[player->y][player->x] = 'P';
	}
	if (game->collected_collectibles == game->total_collectibles)
		game->exit_open = 1;
}

void check_exit(t_game *game, t_player *player)
{
		if (game->map[player->y][player->x] == 'E' && game->exit_open)
		{
			ft_printf("Congratulations You Won :D, Opening The Exit\n");
		}
}

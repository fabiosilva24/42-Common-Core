//check for exit if its E
//exit only available when collecting all the coins
//mark how manny times you clicked on the buttons

#include "../include/so_long.h"

void check_collectible(t_game *game, t_player *player)
{
	if (game->map[player->y][player->x] == 'C')
	{
		game->collected_collectibles++;
		game->map[player->y][player->x] = '0';  // Remove the collectible from the map
		ft_printf("Collectible found! Total collected: %d / %d\n", 
				  game->collected_collectibles, game->total_collectibles);
	}
	if (game->collected_collectibles == game->total_collectibles)
		game->exit_open = 1;
}

void check_exit(t_game *game, t_player *player)
{
	if (game->map[player->y][player->x] == 'E' && game->collected_collectibles == game->total_collectibles)
	{
		ft_printf("Congratulations! You've completed the game in %d moves.\n", game->move_count);
		game->should_end = 1;
	}
	else if (game->map[player->y][player->x] == 'E')
	{
		ft_printf("You've reached the exit, but you haven't collected all items yet!\n");
		ft_printf("Collected: %d / %d\n", game->collected_collectibles, game->total_collectibles);
	}
}

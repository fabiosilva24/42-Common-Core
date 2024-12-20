#include "../include/so_long.h"

void check_fordup(t_game *game)
{
  if (game->player_count > 1)
  {
     ft_printf("Error: 2 players found in the map :( \n)");
     cleanup_game(game);
     exit(EXIT_FAILURE);
  }
}
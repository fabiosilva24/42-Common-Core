void check_fordup(t_game *player)
{
  if (game->player == 2)
  {
     printf("Error: 2 players in the game");
     exit(EXIT_FAILURE);
  }
}
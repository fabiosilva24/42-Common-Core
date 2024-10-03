void cleanup_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}
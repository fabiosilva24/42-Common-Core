void cleanup_game(t_game *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->background_img)
		mlx_destroy_windows(game->mlx_ptr, game->background_img);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
}

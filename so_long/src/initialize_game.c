void initialize_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "So Long");
	if (!game->win_ptr)
		exit(1);

}
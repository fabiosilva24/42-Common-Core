void render_game(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->background_image, 0, 0);


}

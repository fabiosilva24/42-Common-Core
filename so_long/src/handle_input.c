void handle_input(t_game *game)
{
	mlx_key_hook(game->win_ptr,handle_keypress,game);

}
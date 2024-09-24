#include "./src/so_long.h"

void initialize_game(t_game *game)
{
	game->mlx_ptr = mlx_inti();
	if (!game->mlx_ptr)
		exit (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "So Long");
	if (!game->win_ptr)
		exit(1);

}

void handle_input(t_game *game)
{

}

void render_game(t_game *game)
{

}

void cleanup_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}

int main(void)
{
	t_game game;

	initialize_game(&game);



	cleanup_game(&game);

}

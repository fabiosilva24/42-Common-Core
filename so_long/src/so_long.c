#include "../include/so_long.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

void initialize_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "So Long");
	if (!game->win_ptr)
		exit(1);

}

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	game->player.y -= 1;
	else if (keycode == KEY_A)
	game->player.x -= 1;
	else if (keycode == KEY_S)
	game->player.y += 1;
	else if (keycode == KEY_D)
	game->player.x += 1;
	else if (keycode == KEY_ESC)
	exit(0);
	
	return (0);
}

void handle_input(t_game *game)
{
	mlx_key_hook(game->win_ptr,handle_keypress,game);

}

void render_game(t_game *game)
{
	(void)game;
}

void cleanup_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}

int main(void)
{
	t_game game;
	
	
	initialize_game(&game);
	handle_input(&game);

	cleanup_game(&game);
	
	mlx_loop(game.mlx_ptr);

}

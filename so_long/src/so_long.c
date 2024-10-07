#include "../include/so_long.h"

int main(void)
{
	t_game game;
	
	
	initialize_game(&game);
	
	handle_input(&game);

	mlx_loop_hook(game.mlx_ptr, render_game, &game);
	
	mlx_loop(game.mlx_ptr);
	
	cleanup_game(&game);
	
}

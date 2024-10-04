#include "../include/so_long.h"

int main(void)
{
	t_game game;
	
	
	initialize_game(&game);
	handle_input(&game);

	cleanup_game(&game);
	
	mlx_loop(game.mlx_ptr);

}

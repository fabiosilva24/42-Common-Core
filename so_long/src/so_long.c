#include "../include/so_long.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

int main(void)
{
	t_game game;
	
	
	initialize_game(&game);
	handle_input(&game);

	cleanup_game(&game);
	
	mlx_loop(game.mlx_ptr);

}

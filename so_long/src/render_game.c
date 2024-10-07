#include "../include/so_long.h"

int render_game(void *param)
{
	t_game *game = (t_game *)param;
	
	mlx_clear_window(game->mlx_ptr, game->win_ptr);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->background_image, 0, 0);

	return 0;
}

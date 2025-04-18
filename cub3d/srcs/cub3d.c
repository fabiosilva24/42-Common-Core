#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_game game;
    (void)argc;
    (void)argv;
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "CUB3D");
    mlx_loop(game.mlx_ptr);
    return (0);
}
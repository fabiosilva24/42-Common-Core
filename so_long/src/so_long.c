#include "../include/so_long.h"
#include <stdio.h>


int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 9)
		exit(0);
	if (keycode == 25)
		printf("W key pressed\n");
	if (keycode == 38)
		printf("A key pressed\n");
	if (keycode == 39)
		printf("S key pressed\n");
	if (keycode == 40)
		printf("D key pressed\n");
	
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

#include "../include/so_long.h"

// Function to handle key events
int key_hook(int keycode, t_vars *vars)
{
    if (keycode == 65307) // ESC key
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int main(void)
{
    t_vars vars;

    // Initialize MiniLibX
    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (EXIT_FAILURE);

    // Create a new window
    vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "So Long Test");
    if (!vars.win)
    {
        free(vars.mlx);
        return (EXIT_FAILURE);
    }

    // Fill the window with a color (e.g., blue)
    mlx_clear_window(vars.mlx, vars.win);
    mlx_pixel_put(vars.mlx, vars.win, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0x00FF0000); // Draw a red pixel in the center

    // Set up the key hook
    mlx_key_hook(vars.win, key_hook, &vars);

    // Start the MiniLibX loop
    mlx_loop(vars.mlx);

    // Clean up (this line will never be reached in this simple example)
    mlx_destroy_window(vars.mlx, vars.win);
    free(vars.mlx);
    return (EXIT_SUCCESS);
}


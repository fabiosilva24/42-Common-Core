void draw_collectibles_count(t_game *game)
{
    char *count_str;
    char *display_str;


    count_str = ft_itoa(game->collected_collectibles);
    if (!count_str)
    {
        ft_printf("Error: Failed to convert collected collectibles to string");
        exit(EXIT_FAILURE);
    }
    display_str = ft_strjoin("Collected: ", count_str);
    if (!display_str)
    {
        ft_printf("Error: Failed to create display string");
        free(count_str);
        exit(EXIT_FAILURE);
    }
    mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0xFFFFFF, display_str);
    free(count_str);
    free(display_str);
}
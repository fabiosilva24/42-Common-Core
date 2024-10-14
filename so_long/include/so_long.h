/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:40:49 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/10/14 16:22:40 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_player
{
	int x;
	int y;
} t_player;

typedef struct s_game
{
	void *mlx_ptr; // pointer of connction mlx
	void *win_ptr; // pointer to the window of the game
	void *mlx_win;
	t_player player;
	char  **map;
	int collectible;
	int numb_rows;

} t_game;


void initialize_game(t_game *game);
void handle_input(t_game *game);
int render_game(void *param);
void cleanup_game(t_game *game);
int handle_keypress(int keycode, t_game *game);
int map_draw(t_game *game, char *file);
int is_rectangle(t_game *game);
int check_top(t_game *game);
int check_bottom(t_game *game);
int check_sides(t_game *game);
int is_closed_by_walls(t_game *game);


#endif

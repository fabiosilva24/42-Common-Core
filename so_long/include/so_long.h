/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:40:49 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/03/04 19:35:31 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

#define UP_ARROW 65362
#define DOWN_ARROW 65364
#define RIGHT_ARROW 65363
#define LEFT_ARROW 65361


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_monster
{
	int direction;
	int new_x;
	int new_y;
	int monster_count;
} t_monster;
typedef struct s_player
{
	int x;
	int y;
	int player;
	
} t_player;

typedef struct s_game
{
	void *mlx_ptr; // pointer of connction mlx
	void *win_ptr; // pointer to the window of the game
	void *mlx_win;
	void *player_img;
	void *floor_img;
	void *wall_img;
	void *exit_img;
	void *up_img;
	void *collectible_img;
	void *right_img;
	void *left_img;
	void *down_img;
	void *monster_img;
	t_player player;
	char  **map;
	int collectible;
	int total_collectibles;
	int collected_collectibles;
	int exit_open;
	int numb_rows;
	int move_count;
	char *map_file;
	int	map_width;
    int	map_height;
	int should_end;
	int player_found; 
	int key_pressed;
} t_game;



int render_game(void *param);
int	handle_keypress(int keycode, t_game *game, int new_x, int new_y);
int map_draw(t_game *game);
int is_rectangle(t_game *game);
int check_top(t_game *game);
int check_bottom(t_game *game);
int check_sides(t_game *game);
int count_lines(char *file);
int	is_mapber(char *filename);
int	read_map_lines(t_game *game, int fd, int line_count);
int	is_closed_by_walls(t_game *game);
int	is_valid_move(t_game *game, t_player next);
int	get_map_dimensions(t_game *game, int *width, int *height);
void	check_collectible(t_game *game, t_player *player);
void	check_exit(t_game *game, t_player *player);
void	flood_fill(t_game *game, t_player size, t_player cur, char to_fill);
void	handle_player_move(t_game *game, t_player *player, int new_x, int new_y);
void	load_images(t_game *game);
void	draw_tile(t_game *game, int x, int y);
void 	cleanup_game(t_game *game);
void 	initialize_game(t_game *game, char *file);
void	setup_game(t_game *game);
void	count_collectibles(t_game *game);
void	find_player_position(t_game *game);
void 	handle_input(t_game *game);
void 	update_movecount(t_game *game);
void	map_dont_draw(t_game *game);
int 	handle_window_close(t_game *game);
int 	render_game_wrapper(void *param);
void	player_notfound(t_game *game);
void 	draw_move_count(t_game *game);
void	load_images2(t_game *game);
void	cleanup_textures(t_game *game);





#endif





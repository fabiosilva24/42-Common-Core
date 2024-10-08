/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:40:49 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/09/26 14:32:30 by fsilva-p         ###   ########.fr       */
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

typedef struct s_player
{
	int x;
	int y;
} t_player;

typedef struct s_game
{
	void *mlx_ptr; // pointer of connction mlx
	void *win_ptr; // pointer to the window of the game
	t_player player;
	void *background_image;
	int bg_width;
	int bg_height;
	
} t_game;


void initialize_game(t_game *game);
void handle_input(t_game *game);
int render_game(void *param);
void cleanup_game(t_game *game);
int handle_keypress(int keycode, t_game *game);


#endif

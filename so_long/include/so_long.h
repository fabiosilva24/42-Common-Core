/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:40:49 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/09/24 16:07:31 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_game
{
	void *mlx_ptr; // pointer of connction mlx
	void *win_ptr; // pointer to the window of the game
	
} t_game;

void initialize_game(t_game *game);
void handle_input(t_game *game);
void render_game(t_game *game);
void cleanup_game(t_game *game);


#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:41:48 by fsilva-p          #+#    #+#              #
#    Updated: 2024/12/20 20:07:32 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(MLX_PATH) -g

MLX_PATH = ./libs/minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lX11 -lXext -lm
MLX = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ./src/so_long.c\
	./src/cleanup_game.c\
	./src/flood_fill.c\
	./src/handle_input.c\
	./src/handle_keypress.c\
	./src/initialize_game.c\
	./src/map_check.c\
	./src/map_draw.c\
	./src/map_parse.c\
	./src/render_game.c\
	./src/draw_tile.c\
	./src/count_lines.c\
	./src/map_dontdraw.c\
	./src/player_and_collectibles.c\
	./src/game_setup.c\
	./src/player_notfound.c\
	./libs/get_next_line/get_next_line.c\
	./libs/get_next_line/get_next_line_utils.c\
	./src/check_fordup.c\
	./src/free_map.c\
	./src/free_textures.c
	
 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean  -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re

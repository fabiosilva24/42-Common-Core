# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:41:48 by fsilva-p          #+#    #+#              #
#    Updated: 2024/10/07 16:05:14 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(MLX_PATH)

MLX_PATH = ./libs/minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lX11 -lXext -lm
MLX = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ./src/so_long.c\
	./src/handle_input.c\
	./src/handle_keypress.c\
	./src/initialize_game.c\
	./src/render_game.c\
	./src/cleanup_game.c
	./src/map_draw.c
 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(LIBFT):
	make -C libft

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

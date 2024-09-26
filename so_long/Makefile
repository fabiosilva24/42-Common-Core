# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:41:48 by fsilva-p          #+#    #+#              #
#    Updated: 2024/09/26 15:20:47 by fsilva-p         ###   ########.fr        #
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

SRCS = ./src/so_long.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

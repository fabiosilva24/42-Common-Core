# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:41:48 by fsilva-p          #+#    #+#              #
#    Updated: 2024/07/23 16:54:53 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC == gcc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT) -I $(MLX)
MLX = ./minilibx-linux/libmlx.a
LIBFT = libft/libft.a
SRC_DIR = src
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

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

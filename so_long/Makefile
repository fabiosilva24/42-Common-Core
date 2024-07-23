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

# Program Name
NAME = so_long

# Compiler And CFlags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT) -I $(MLX)
LIBS = -lXext -lX11 -lm
MLX = ./minilibx-linux/libmlx.a
LIBFT = ./libft/libft.a
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) $(MLX) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx-linux


clean:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C ./minilibx-linux

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make clean -c ./minilibx-linux

re: fclean all

.PHONY: all clean fclean re

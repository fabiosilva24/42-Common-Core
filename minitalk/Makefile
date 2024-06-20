# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:41:53 by fsilva-p          #+#    #+#              #
#    Updated: 2024/06/20 17:41:57 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
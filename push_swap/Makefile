# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 16:16:01 by fsilva-p          #+#    #+#              #
#    Updated: 2024/10/21 16:16:04 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)

%.o: %.c
$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
rm -f $(OBJS)

fclean: clean
rm -f $(NAME)

.PHONY: all fclean clean re

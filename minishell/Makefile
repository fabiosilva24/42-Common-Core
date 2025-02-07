# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 14:37:09 by fsilva-p          #+#    #+#              #
#    Updated: 2025/02/06 16:07:32 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m
CYAN := \033[0;36m
NC := \033[0m

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
READLINEFLAG = -lreadline

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ./srcs/minishell.c\
		./srcs/print_banner.c\
		./srcs/handle_quotes.c\
		./srcs/get_env.c\
		./builtins/echo.c\
		./tokens/token.c\
		./srcs/ft_strtok.c\
		./srcs/parse_input.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo "$(CYAN)Making...$(NC)"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(READLINEFLAG)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	@echo "$(GREEN)Cleaning...$(NC)"
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all fclean clean re

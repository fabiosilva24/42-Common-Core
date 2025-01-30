# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 14:37:09 by fsilva-p          #+#    #+#              #
#    Updated: 2025/01/30 17:41:40 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m
CYAN := \033[0;36m
NC := \033[0m

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/minishell.c\
		./srcs/print_banner.c\
		./srcs/handle_quotes.c\
		./srcs/get_env.c\
		./builtins/echo.c\
		./tokens/token.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "$(CYAN)Making...$(NC)"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	@echo "$(GREEN)Cleaning...$(NC)"
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re

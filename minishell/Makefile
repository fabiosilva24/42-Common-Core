# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 14:37:09 by fsilva-p          #+#    #+#              #
#    Updated: 2025/02/07 16:32:32 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

GREEN := \033[0;32m
PASTEL_GREEN := \033[38;5;120m
CYAN := \033[0;36m
NC := \033[0m

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
READLINEFLAG = -lreadline

SRCS = ./srcs/minishell.c\
		./srcs/print_banner.c\
		./srcs/handle_quotes.c\
		./srcs/get_env.c\
		./builtins/echo.c\
		./tokens/token.c\
		./srcs/ft_strtok.c\
		./srcs/parse_input.c

OBJS = $(SRCS:.c=.o)

COUNT = 0
TOTAL = $(words $(SRCS))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(CYAN)Making...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(READLINEFLAG)

%.o: %.c
	$(eval COUNT=$(shell echo $$(($(COUNT) + 1))))
	@echo "$(PASTEL_GREEN)[$(COUNT)/$(TOTAL)] Compiling $<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@echo "$(GREEN)Cleaning...$(NC)"
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all fclean clean re $(LIBFT)

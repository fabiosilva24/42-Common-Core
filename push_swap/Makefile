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
GREEN := \033[0;32m
CYAN := \033[0;36m
NC := \033[0m
NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = handle_errors.c\
	init_a_to_b.c\
	init_b_to_a.c\
	modified_ftsplit.c\
	push.c\
	push_swap.c\
	reverse.c\
	rotate.c\
	sort_stacks.c\
	sort_three.c\
	stack_init.c\
	stack_outils.c\
	swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo "$(CYAN)Making...$(NC)"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)		

clean:
	@echo "$(GREEN)Cleaning...$(NC)"
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all fclean clean re

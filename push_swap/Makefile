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
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = srcs/handle_errors.c\
    srcs/init_a_to_b.c\
    srcs/init_b_to_a.c\
    srcs/modified_ftsplit.c\
    srcs/push.c\
    srcs/push_swap.c\
    srcs/reverse.c\
    srcs/rotate.c\
    srcs/sort_stacks.c\
    srcs/sort_three.c\
    srcs/stack_init.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
    @$(MAKE) -C $(LIBFT_PATH)
    @$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
    @echo "$(GREEN)$(NAME) compiled successfully!$(NC)"

clean:
    @$(MAKE) -C $(LIBFT_PATH) clean
    @rm -f $(OBJS)
    @echo "$(CYAN)Object files cleaned!$(NC)"

fclean: clean
    @$(MAKE) -C $(LIBFT_PATH) fclean
    @rm -f $(NAME)
    @echo "$(CYAN)Executable cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re

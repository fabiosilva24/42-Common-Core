# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 22:40:25 by fsilva-p          #+#    #+#              #
#    Updated: 2025/01/25 22:40:25 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m
CYAN := \033[0;36m
NC := \033[0m

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/philo_routine.c\
		./srcs/philo_utils.c\
		./srcs/philo_actions.c\
		./srcs/philo.c\
		./srcs/parse_input.c\
		./srcs/init_simulation.c\
		./srcs/take_forks.c\
		./srcs/cleanup_simulation.c\
		./srcs/check_end_simulation.c\
		./srcs/threads.c\
		./srcs/handle_errors.c\
		./srcs/philo_eat_utils.c

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
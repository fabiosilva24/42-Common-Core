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

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "$(CYAN)Making...$(NC)"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	@echo "$(GREEN)Cleaning...$(NC)"
	rm -f $(OBJS)
	make clean -C

fclean: clean
	rm -f $(NAME)
	make fclean -C

re: fclean all

.PHONY: all fclean clean re
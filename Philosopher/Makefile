GREEN := \033[0;32m
CYAN := \033[0;36m
NC := \033[0m
NAME = philo_one
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 
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
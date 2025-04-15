GREEN := \033[0;32m
CYAN := \033[0;36m
NC := \033[0m

NAME = CUB3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = ./srcs/map_extension_check.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo "$(CYAN)Making...$(NC)"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

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

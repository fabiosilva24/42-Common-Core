GREEN := \033[0;32m
CYAN  := \033[0;36m
NC    := \033[0m

NAME    = CUB3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

LIBS_DIR   = ./libs
LIBFT_PATH = $(LIBS_DIR)/libft
LIBFT      = $(LIBFT_PATH)/libft.a
MLX_PATH   = $(LIBS_DIR)/minilibx
MLX_LIB    = $(MLX_PATH)/libmlx.a

SRCS = ./srcs/cub3d.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(MLX_PATH) -I$(LIBFT_PATH)
LDFLAGS  = -L$(MLX_PATH) -lmlx -lm -L/usr/lib -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@echo "$(CYAN)Making...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBFT) $(LDFLAGS)

$(LIBFT):
	@echo "$(CYAN)Building Libft...$(NC)"
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB): clone_mlx
	@echo "$(CYAN)Building MiniLibX...$(NC)"
	$(MAKE) -C $(MLX_PATH)


clone_mlx:
	@mkdir -p $(LIBS_DIR)
	@if [ ! -d $(MLX_PATH) ]; then \
		echo "$(CYAN)Cloning MiniLibX...$(NC)"; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH); \
	fi
	@echo "$(CYAN)Building MiniLibX...$(NC)"
	$(MAKE) -C $(MLX_PATH)

clean:
	@echo "$(GREEN)Cleaning...$(NC)"
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_PATH)
	@if [ -d $(MLX_PATH) ]; then $(MAKE) clean -C $(MLX_PATH); fi

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re clone_mlx

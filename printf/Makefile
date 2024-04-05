CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = print_char.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	cp libft/libft.a libftprintf.a
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)

.PHONY: all fclean clean re

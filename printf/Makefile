CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = 	ft_calloc.c\
	ft_memset.c\
	ft_itoa.c\
	ft_printf.c\
	ft_printhexa.c\
	ft_printpercent.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putpr.c\
	ft_putstr.c\
	ft_putunsigned.c\
	

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)

.PHONY: all fclean clean re

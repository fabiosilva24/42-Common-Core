CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_atoi.c\
ft_strncmp.c\
ft_memcmp.c\
ft_strlen.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memmove.c\
ft_memchr.c\
ft_calloc.c\
ft_strnstr.c\
ft_strdup.c\
ft_substr.c

OBJS = $(SRCS:.c=.o)

all: libft.a

libft.a : $(OBJS)
	ar rc libft.a $(OBJS)

	
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

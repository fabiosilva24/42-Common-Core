# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 12:08:35 by fsilva-p          #+#    #+#              #
#    Updated: 2025/02/07 12:24:22 by fsilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
NAME = libft.a
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
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_striteri.c\
ft_printf.c\
ft_deci_to_hexa.c\
ft_deci_to_hexauppercase.c\
ft_printpercent.c\
ft_putchar.c\
ft_putnbr.c\
ft_putptr.c\
ft_putstr.c\
ft_putunsigned.c\
ft_isspace.c

BONUS_SRCS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

	
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	
bonus: $(BONUS_OBJS)
		ar rcs $(NAME) $(BONUS_OBJS)

.PHONY: all fclean clean re bonus

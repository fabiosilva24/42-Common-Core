/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:44:14 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/02/07 12:24:14 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int		ft_isalpha(int c); //done
int		ft_isdigit(int arg); //done
int		ft_isalnum(int c); //done
int		ft_isascii(int c); //done
int		ft_isprint(int arg); //done
int		ft_toupper(int c);//done
int 	ft_isspace(int argument);
int		ft_tolower(int c); //done
int		ft_atoi(const char *str);//done
int		ft_strncmp(const char *str1, const char *str2, size_t n); //done
int		ft_memcmp(const void *str1, const void *str2, size_t n); //done
size_t	ft_strlen(const char *str); //done
size_t	ft_strlcpy(char *dst, const char *src, size_t size); //done
size_t	ft_strlcat(char *dst, const char *src, size_t size); //done
char	*ft_strchr(const char *str, int c); //done
char	*ft_strrchr(const char *str, int c); //done
void	*ft_memset(void *str, int c, size_t n); //done
void	ft_bzero(void *s, size_t n); //done
void	*ft_memcpy(void *dest, const void *src, size_t n); //done
void	*ft_memmove(void *dest, const void *src, size_t n); //done
void	*ft_memchr(const void *str, int c, size_t n); //done
void	*ft_calloc(size_t nitems, size_t size); //done
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *src); //done
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int num);
int		ft_putptr(unsigned long long ptr);
int		ft_deci_to_hexa(unsigned long n);
int		ft_deci_to_hexauppercase(unsigned long n);
int		ft_printpercent(void);

#endif

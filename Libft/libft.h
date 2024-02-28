/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:44:14 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/28 16:44:09 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

int		ft_isalpha(int c); //done
int		ft_isdigit(int arg); //done
int		ft_isalnum(int c); //done
int		ft_isascii(int c); //done
int		ft_isprint(int arg); //done
int		ft_toupper(int c);//done
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

#endif

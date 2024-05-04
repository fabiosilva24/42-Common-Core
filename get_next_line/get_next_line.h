/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:49:31 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/05/04 15:00:41 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memset(void *str, int c, size_t n);
char	*checkfornewline(char *buffer);
char	*ft_freejoin(char *buffer, char *buf);
char	*read_file(int fd, char *result);
char	*ft_next(char *buffer);
char	*ft_strchr(const char *str, int c);

#endif

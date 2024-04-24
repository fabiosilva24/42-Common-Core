/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:49:31 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/04/24 18:58:40 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	char	letter;
	struct s_list *next;
}	t_list;

char *get_next_line(int fd);

#endif

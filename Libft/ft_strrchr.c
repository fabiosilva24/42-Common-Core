/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:24:47 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/26 19:37:29 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	char			*h;
	char			cc;
	unsigned int	i;

	cc = (char)c;
	h = NULL;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == cc)
		{
			h = (char *)&str[i];
		}
		i++;
	}
	if (!h && str && str[i] == cc)
	{
		h = (char *)&str[i];
	}
	return (h);
}
/*int main(int argc, char *argv[])
{
	char *string = "Hello, World!";
	char *first_W = ft_strrchr(string, 'l');
	printf("first_W: %s\n", first_W);
	char *first_P = ft_strrchr(string, 'P');
	
	if (first_P == NULL)
	printf("P not found\n");
}*/

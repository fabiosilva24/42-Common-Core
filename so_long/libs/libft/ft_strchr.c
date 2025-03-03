/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:25:03 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/03/09 15:09:11 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
/*int main(int argc, char *argv[])
{
	char *string = "Hello, World!";
	char *first_W = ft_strchr(string, 'l');
	printf("first_W: %s\n", first_W);
	char *first_P = ft_strchr(string, '\0');
	
	if (first_P == NULL)
	printf("P not found\n");
}*/

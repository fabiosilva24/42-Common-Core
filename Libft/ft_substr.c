/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:27:56 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/03/11 17:32:16 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		i;
	size_t		dlen;

	i = 0;
	if (start > ft_strlen(s))
	{
		substring = (char *)malloc(1);
		substring[0] = 0;
		return (substring);
	}
	dlen = ft_strlen(s + start);
	if (len > dlen)
		len = dlen;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
/*#include "stdio.h"
int main()
{
	const char	*string = "tripouille";
	unsigned int	start = 100;
	size_t	length = 1;
	char	*substring;
	
	substring = ft_substr(string, start, length);
	
	if (substring == NULL)
	{
		printf("Memory Aloccation Failed.\n");
		return 1; // Exit with an error code
	}
	
	printf ("Substring: %s\n", substring);
	
	
	free(substring);
	
	return (0);
}*/	

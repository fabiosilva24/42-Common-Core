/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:39:33 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/20 18:45:59 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 'a');
	}
	return (c);
}
/*#include <stdio.h>

int main(void) 
{
    char c;
    printf("Enter a character: ");
    c = getchar(); // get a character from the user
    c = tolower(c); // convert the character to uppercase
    printf("Lowercase: %c\n", c); // print the uppercase character
    return  0;
}*/

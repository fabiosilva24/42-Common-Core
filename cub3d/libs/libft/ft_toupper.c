/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:17:10 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/20 18:38:49 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 'A');
	}
	else
	{
		return (c);
	}
}
/*#include <stdio.h>

int main(void) {
    char c;
    printf("Enter a character: ");
    c = getchar(); // get a character from the user
    c = toupper(c); // convert the character to uppercase
    printf("Uppercase: %c\n", c); // print the uppercase character
    return  0;
}*/	

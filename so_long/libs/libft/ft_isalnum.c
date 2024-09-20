/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:55:49 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/23 17:09:02 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*#include <ctype.h>
#include <stdio.h>

int main() {
    char c = '-';
    if (isalnum(c)) {
        printf("%c is an alphanumeric character.\n", c);
    } else {
        printf("%c is not an alphanumeric character.\n", c);
    }
    return  0;
}*/

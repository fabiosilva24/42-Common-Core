/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:02:01 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/28 19:02:07 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    // Calculate the lengths of s1 and s2
    size_t len_s1 = 0;
    while (s1[len_s1] != '\0')
        len_s1++;

    size_t len_s2 = 0;
    while (s2[len_s2] != '\0')
        len_s2++;

    // Calculate the total length of the new string
    size_t new_len = len_s1 + len_s2;

    // Allocate memory for the new string
    char *new_str = (char *)malloc((new_len + 1) * sizeof(char));
    if (new_str == NULL)
        return NULL;

    // Copy s1 to new_str
    size_t i = 0;
    for (; i < len_s1; i++)
        new_str[i] = s1[i];

    // Copy s2 to new_str
    for (size_t j = 0; j < len_s2; j++)
        new_str[i++] = s2[j];

    // Null-terminate the new string
    new_str[new_len] = '\0';

    return new_str;
}

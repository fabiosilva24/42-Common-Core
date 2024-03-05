/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:36:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/02/27 15:38:12 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)

{	
	size_t	total_size;
	void	*ptr;

	if (size == 0 || nitems == 0)
	{	
		return (malloc(1));
	}
	total_size = nitems * size;
	ptr = malloc(total_size);
	if (SIZE_MAX / size < nitems)
	{
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (NULL);
	}
	memset(ptr, 0, total_size);
	return (ptr);
}
/*int main()
{
    int *ptr = ft_calloc(10, sizeof(int));
    printf("Set  10 blocks to  0\n");
    for (int i =  0; i <  10; i++)
    {
        printf("%d ", ptr[i]);
    }
    free(ptr); // Don't forget to free the allocated memory
    return  0;
}*/

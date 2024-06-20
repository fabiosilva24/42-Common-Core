/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:30:09 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/06/20 18:22:35 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"

void	handle_signal(int signal)
{
	static int	bits = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c |= (0 << bits);
	else if (signal == SIGUSR2)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}

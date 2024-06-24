/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:23:43 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/06/24 17:23:47 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk_bonus.h"


void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bits = 0;
	static char	c = 0;
	int pid;

	(void)context;
	pid = info->si_pid;

	if (signal == SIGUSR1)
		c |= (0 << bits);
	else if (signal == SIGUSR2)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		if (c == 0)
			kill(pid, SIGUSR2);
		c = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "error", 1);
		return 1;
	}

	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		pause();
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:23:43 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/07/18 16:31:01 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk_bonus.h"

int	check_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		return (1);
	}
	if (sigaction(SIGUSR2, sa, NULL) == -1)
	{
		return (1);
	}
	return (0);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bits = 0;
	static char	c = 0;
	int			pid;

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
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (check_sigaction(&sa))
	{
		write(1, "error", 5);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}

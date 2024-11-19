/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:23:31 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/07/03 14:23:29 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk_bonus.h"

static int	g_status;

int	check_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		return (1);
	}
	if (sigaction(SIGUSR2, sa, NULL) == 1)
	{
		return (1);
	}
	return (0);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)signal;
	g_status = 1;
	if (signal == SIGUSR2)
		ft_printf("message acknowledged\n");
}

void	send_char(pid_t pid, char c)

{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_status = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_status == 0)
			usleep(10);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*message;
	int					i;
	struct sigaction	sa;

	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (check_sigaction(&sa))
	{
		write(1, "error", 1);
	}
	if (argc != 3)
	{
		ft_printf("Use: %s <server_pid> <message>", argv[0]);
		return (1);
	}
	while (message[i] != '\0')
		send_char(server_pid, message[i++]);
	send_char(server_pid, '\0');
}

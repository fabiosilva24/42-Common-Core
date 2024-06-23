#include <unistd.h>
#include "minitalk_bonus.h"
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

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		i;
	struct sigaction sa;
	
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;

	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "error", 1);
		return 1;
	}
	if (argc != 3)
	{
		ft_printf("Use: %s <server_pid> <message>", argv[0]);
		return (1);
	}
	while (message[i] != '\0')
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');

	pause();

	return (0);
}

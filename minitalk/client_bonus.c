#include <unistd.h>
#include "minitalk_bonus.h"

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

	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
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
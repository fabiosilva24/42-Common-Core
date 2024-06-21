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

int	main(void)
{
		struct sigaction sa;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(1, "error", 1)
		return 1;
	}

	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
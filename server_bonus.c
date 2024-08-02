#include "minitalk_bonus.h"

pid_t	g_pid;

/**
 * POSIX SA_SIGINFO:
 * void	sighandler(int signal, siginfo_t *info, ucontext_t *uap)
 * * if (byte_received == '\0')
 * * kill (pid, SIGUSR1);
*/
void	sig_handler(int signal, siginfo_t *info, void *uap)
{
	static int	index = 0;
	static int	byte_received = 0;

	(void)uap;
	if (signal == SIGINT)
	{
		ft_printf ("client pid= {%i}\n", info->si_pid);
		if (kill (info->si_pid, SIGINT) == 0)
			perr("Exiting due to channel error");
		else
			perr("Could not send SIGINT to channel");
	}
	if (signal == SIGUSR1)
		byte_received |= (0x01 << index);
	index++;
	if (index == 8)
	{
		if (byte_received == 0)
			kill (info->si_pid, SIGUSR1);
		ft_printf("%c", byte_received);
		if (!byte_received)
			ft_printf("\n");
		byte_received = 0;
		index = 0;
		usleep(250);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	action;

	(void)av;
	if (1 != ac)
		return (mperr("\"./server\" accepts no arguments."), 1);
	g_pid = getpid();
	ft_printf("\e[32m-----------------\n PID is: ");
	ft_printf("%d\n-----------------\e[0m\n", g_pid);
	action.sa_sigaction = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	while (1)
	{
		sigaction(SIGINT, &action, NULL);
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
}

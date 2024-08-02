#include "minitalk.h"

pid_t	g_pid;

/**
 * Function receive_signal handles:
 * * Sending of ACK signal to client
 * * Server side channel errors
 * 
 * (int signal, siginfo_t *info, ucontext_t *uap)
 * aka struct __darwin_ucontext *uap
*/
void	sig_handler(int signal, siginfo_t *info, void *uap)
{
	static int	index = 0;
	static int	byte_received = 0;

	(void)info;
	(void)uap;
	if (signal == SIGINT)
	{
		if (kill(g_pid, SIGINT) == 0)
			perr("Exiting due to channel error");
		else
			perr("Could not send SIGINT to channel");
	}
	if (signal == SIGUSR1)
		byte_received |= (0x01 << index);
	index++;
	if (index == 8)
	{
		ft_printf("%c", byte_received);
		if (!byte_received)
			ft_printf("\n");
		byte_received = 0;
		index = 0;
	}
	usleep(250);
}

// struct  sigaction {
// 		union __sigaction_u __sigaction_u;  /* signal handler */
// 		sigset_t sa_mask;               /* signal mask to apply */
// 		int     sa_flags;               /* see signal options below */
// };

int	main(int ac, char *av[])
{
	struct sigaction	act;
	struct sigaction	oact;

	(void)av;
	(void)oact;
	if (1 != ac)
		return (mperr("\"./server\" accepts no arguments."), 1);
	g_pid = getpid();
	ft_printf("\e[32m-----------------\n PID is: ");
	ft_printf("%d\n-----------------\e[0m\n", g_pid);
	act.sa_sigaction = sig_handler;
	oact.sa_sigaction = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (1)
	{
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}

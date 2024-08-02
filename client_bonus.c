#include "minitalk_bonus.h"

/* Global PID */
pid_t	g_pid;

/**
 * Function sighandler handles:
 * * Client side channel errors (exit with FAILURE status)
 * * Server side ACK signals (exit with SUCCESS status)
*/
void	sig_handler(int signal, siginfo_t *info, void *uap)
{
	(void)uap;
	if (signal == SIGINT)
	{
		if (kill(info->si_pid, SIGINT) == -1)
			perr("Could not send SIGINT to channel");
		else
			perr("Exiting due to channel error");
	}
	else if (signal == SIGUSR1)
	{
		ft_printf("\e[32mACK signal from server received\e[0m\n");
		exit (EXIT_SUCCESS);
	}
}

/**
 * * Function sig_send sends a string to the server
 * * using SIGUSR1 and SIGUSR2 signals
*/
void	sig_send(char *str, size_t strlen)
{
	size_t	index;
	int		bit_shift;

	index = 0;
	if (g_pid > 4194304)
		perr("invalid pid: HINT! are you in range of pid?");
	while (index <= strlen)
	{
		bit_shift = 0;
		while (bit_shift < 8)
		{
			if ((str[index] >> bit_shift) & 1)
				kill(g_pid, SIGUSR1);
			else
				kill(g_pid, SIGUSR2);
			bit_shift++;
			usleep(300);
		}
		index++;
	}
}

/**
 * Function validate_pid
 * returns g_pid aka 'Global PID'
 * accepts +ve & -ve PID
 * increments through 
*/
int	validate_pid(char *spid)
{
	int	offset;

	offset = 0;
	if (spid[offset] == '+' || spid[offset] == '-')
		offset++;
	while (ft_isdigit(spid[offset]))
		offset++;
	if (spid[offset] != '\0')
		return (-1);
	g_pid = ft_atoi(spid);
	return (g_pid);
}

int	main(int ac, char *av[])
{
	char				*str;
	struct sigaction	act;

	if (3 != ac || '\0' == av[2][0])
		perr("./client <PID> \"MESSAGE\"");
	g_pid = validate_pid(av[1]);
	if (g_pid == -1)
	{
		ft_printf("\e[31m%s: illegal pid: '%s'\e[0m\n", av[0], av[1]);
		exit (-1);
	}
	act.sa_sigaction = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction (SIGINT, &act, NULL);
	sigaction (SIGUSR1, &act, NULL);
	str = av[2];
	ft_printf("actual client pid = (%i)\n", getpid());
	sig_send(str, ft_strlen(str));
	return (0);
}

#include "minitalk.h"

/* Global PID */
pid_t	g_pid;

/**
 * Function sighandler handles:
 * * Client side channel errors (exit with FAILURE status)
*/
void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		if (kill(g_pid, SIGINT) == -1)
			perr("Could not send SIGINT to channel");
		perr("Exiting due to channel error");
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
		perr("invalid pid: HINT! are you in range of pid_t?");
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
 * Function validate_pid (spid aka PID in string format)
 * * returns g_pid aka 'Global PID'
 * * accepts +ve & -ve PID
 * * increments through
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
	struct sigaction	sa;

	if (3 != ac || '\0' == av[2][0])
		perr("./client <PID> \"MESSAGE\"");
	g_pid = validate_pid(av[1]);
	if (g_pid == -1)
	{
		ft_printf("\e[31m%s: illegal pid: '%s'\e[0m\n", av[0], av[1]);
		exit (-1);
	}
	sa.sa_handler = sig_handler;
	sigaction (SIGINT, &sa, NULL);
	str = av[2];
	sig_send(str, ft_strlen(str));
	return (0);
}

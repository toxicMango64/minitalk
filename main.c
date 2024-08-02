#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pid_t pid;
	
	pid = atoi(av[1]);
	printf (pid);
	if (kill (pid, SIGINT) == -1)
		exit (EXIT_FAILURE);
	return (0);
}
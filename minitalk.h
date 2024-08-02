#ifndef MINITALK_H
# define MINITALK_H

/**
 * #define SIGHUP  1       / hangup /
 * #define SIGINT  2       / interrupt /
 * #define SIGQUIT 3       / quit /
 * #define SIGILL  4       / illegal instruction (not reset when caught) /
 * #define SIGABRT 6       / abort() /
 * #define SIGKILL 9       / kill (cannot be caught or ignored) /
 * #define SIGALRM 14      / alarm clock /
 * #define SIGTERM 15      / software termination signal from kill /
 * #define SIGSTOP 17      / sendable stop signal not from tty /
 * #define SIGTSTP 18      / stop signal from tty /
 * #define SIGCONT 19      / continue a stopped process /
 * #define SIGCHLD 20      / to parent on child stop or exit /
 * #define SIGPROF 27      / profiling time alarm /
 * #define SIGINFO 29      / information request /
 * #define SIGUSR1 30      / user defined signal 1 /
 * #define SIGUSR2 31      / user defined signal 2 /
*/

# include "./libft/libft.h"
# include <signal.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

#endif

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr(char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr(int n);
int		ft_unsignednbr(unsigned int n);
int		ft_lilx(unsigned int num);
int		ft_bigx(unsigned int num);
int		ft_ptrx(unsigned long num);
void	perr(char *str);
void	mperr(char *str);

#endif
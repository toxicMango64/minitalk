#include "ft_printf.h"

static void	ft_border(size_t i)
{
	ft_printf("\n\e[31m");
	while (i > 0)
	{
		ft_printf("-");
		i--;
	}
	ft_printf("\e[0m\n");
}

void	perr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i += 14;
	ft_border(i);
	ft_printf("\e[31m  Error ya: ");
	ft_printf("%s", str);
	ft_border(i);
	exit (EXIT_FAILURE);
}

void	mperr(char *str)
{
	ft_printf("\e[31m--------------------------------------------\n");
	ft_printf("Error ya: ");
	ft_printf("%s", str);
	ft_printf("\n\e[90mKinda reminds me of my wife. cc: ;)");
	ft_printf("\n\e[31m--------------------------------------------\e[0m\n");
}

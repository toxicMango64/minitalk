#include "ft_printf.h"

static	int	ft_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = len + ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = len + ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len = len + ft_unsignednbr(va_arg(args, unsigned int));
	else if (c == 'x')
		len = len + ft_lilx(va_arg(args, unsigned int));
	else if (c == 'X')
		len = len + ft_bigx(va_arg(args, unsigned int));
	else if (c == 'p')
		len = len + ft_ptrx(va_arg(args, unsigned long));
	else if (c == '%')
		len = len + ft_putchar('%');
	else
		len = len + ft_putchar(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(format[++i], args);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (len);
}

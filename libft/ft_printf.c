#include "libft.h"
#include <stdarg.h>

void	ft_printf(int num, ...)
{
	va_list arg;
	char	*next;

	va_start(arg,num);
	while (num > 0)
	{
		next = va_arg(arg, char *);
		ft_putstr(next);
		num--;
	}
	va_end(arg);
}

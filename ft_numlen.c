#include "libft.h"

int			ft_numlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
		{
			i++;
			n /= 10;
		}
	return (i);
}
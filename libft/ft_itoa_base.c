#include <stdlib.h>

int		num_len(int n, int base)
{
	int i;
	i = 0;
	while (n != 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char    *ft_itoa_base(int value, int base)
{
	char	*tab;
	char	*s;
	int		len;
	int		n;

	n = value;
	if (n == 0)
		return ("0");
	tab = "0123456789ABCDEF";
	len	= num_len(ft_abs(n), base);
	if (base == 10 && n < 0)
	{
		len++;
		n *= -1;
	}
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	while (n != 0)
	{
		s[len - 1] = tab[ft_abs(n % base)];
		n /= base;
		len--;
	}
	if (len != 0)
	s[0] = '-';
	return (s);
}

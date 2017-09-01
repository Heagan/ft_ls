#include "lslib.h"

int						ft_islink(int n)
{
	return (n >= 0120000 && n < 0130000);
}

int						ft_isdir(int n, char *dir)
{
	DIR		*dp;

	if (n > 0)
		return (n >= 040000 && n <= 040777);
	if (dir != NULL)
	{
		if ((dp = opendir(dir)) != NULL)
		{
			closedir(dp);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

char					filetype(int n)
{
	if (ft_islink(n))
		return ('l');
	if (ft_isdir(n, NULL))
		return ('d');
	else
		return ('-');
}

char					*fileperm(int n)
{
	char	*c;
	char	*s;

	n %= 512;
	c = ft_itoa_base(n, 8);
	s = getcode(c[0]);
	s = ft_strcat(s, getcode(c[1]));
	s = ft_strcat(s, getcode(c[2]));
	return(s);
}
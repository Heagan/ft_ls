#include "lslib.h"

int					main(int ac, char **av)
{
	int				i;
	t_info			a;
	t_read			r;
	t_lst			*list = NULL;
	t_lst			*tmp;
	t_dir			dir_info;

	a.arg =	ft_strnew(100);
	ft_bzero(a.arg, 100);
	a.line = ft_strnew(50);
	a.line[0] = '.';
	dir_info.b_size = 0;
	dir_info.tabs = 1;
	dir_info.len = 6;
	ft_read_curdir(a.line, &a,  &dir_info, &r);
	if (ac > 1)
	{
		i = -1;
		while (++i < ac)
		{
			if (ft_strchr(av[i], '-') != NULL)
			{
				if (ft_strchr(av[i], 'l') != NULL)
					a.arg =	ft_strcat(a.arg, "l"); 
				if (ft_strchr(av[i], 'a') != NULL)
					a.arg =	ft_strcat(a.arg, "a");	
				if (ft_strchr(av[i], 'r') != NULL)
					a.arg =	ft_strcat(a.arg, "r");	
				if (ft_strchr(av[i], 'R') != NULL)
					a.arg =	ft_strcat(a.arg, "R");	
				if (ft_strchr(av[i], 't') != NULL)
					a.arg =	ft_strcat(a.arg, "t");
				if (ft_strlen(a.arg) == 0)
				{
					ft_putendl("No such file or directory");
					return (0);
				}
			}
			else if (ft_isdir(0, av[i]) && ft_strcmp(av[i], ".") != 0)
			{
				a.line = av[i];
				ft_putstr("\n");
				ft_read_curdir(a.line, &a,  &dir_info, &r);
			}
		}
	}
	return (0);
}

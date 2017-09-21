/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:24:03 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/04 08:24:25 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lslib.h"

int				set_arg(int ac, char **av, t_info *a)
{
	a->i = -1;
	if (ac > 1)
		while (++a->i < ac)
			if (ft_strchr(av[a->i], '-') != NULL)
			{
				if (ft_strchr(av[a->i], 'l') != NULL)
					a->arg = ft_strcat(a->arg, "l");
				if (ft_strchr(av[a->i], 'a') != NULL)
					a->arg = ft_strcat(a->arg, "a");
				if (ft_strchr(av[a->i], 'r') != NULL)
					a->arg = ft_strcat(a->arg, "r");
				if (ft_strchr(av[a->i], 'R') != NULL)
					a->arg = ft_strcat(a->arg, "R");
				if (ft_strchr(av[a->i], 't') != NULL)
					a->arg = ft_strcat(a->arg, "t");
				if (ft_strlen(a->arg) == 0)
					if (!(ft_isdir(0, av[a->i])))
					{
						ft_putendl("No such file or directory");
						return (0);
					}
			}
	return (1);
}

int				loop_av(int ac, char **av, t_info *a)
{
	int			n;

	n = 0;
	a->i = -1;
	while (++a->i < ac)
		if (ft_isdir(0, av[a->i]))
		{
			a->line = av[a->i];
			n++;
			if (n > 1)
				ft_printf(3, "\n", a->line, ":\n");
			ft_read_curdir(a->line, a);
		}
	return (n);
}

int				main(int ac, char **av)
{
	t_info		a;

	a.arg = ft_strnew(100);
	ft_bzero(a.arg, 100);
	a.line = ft_strnew(50);
	a.line[0] = '.';
	if (!(set_arg(ac, av, &a)))
		return (0);
	if (loop_av(ac, av, &a) != 0)
		return (0);
	av[0] = ".";
	loop_av(ac, av, &a);
	return (1);
}

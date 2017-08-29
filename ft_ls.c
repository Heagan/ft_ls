#include "lslib.h"


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
		{
			closedir(dp);
			return (0);
		}
	}
	return (0);
}

void					addentry(t_lst **list, char *name, char *directory)
{
	t_lst 				*temp;
	t_lst 				*current;

	
	current = *list;

	temp = (t_lst *)malloc(sizeof(t_lst));
	temp->next = NULL; 
	temp->dir = ft_strjoin(directory, "/");
	temp->name = ft_strdup(name);
	
	if (*list == NULL)
		*list = temp;
	else
	{
		while(current->next)
			current = current->next;
		current->next = temp;
	}
}

void	ft_getinfo(char *entry, t_stat *statbuf)
{
	lstat(entry, statbuf);
	if 
	printf("%i HELLO\n", statbuf->st_size);
}

void					ft_read_curdir(char *dir, t_info *a, t_dir *info)
{
	t_lst	*tmp = NULL;
	t_lst	*list = NULL;
	char	*rec[255];
	char	*s;
	int		i;
	int		j;

	i = 0;	
	if ((info->dp = opendir(dir)) == NULL)
	{
		printf("Cant open dir %s\n", dir);
		return ;
	}
	
	while ((info->entry = readdir(info->dp)) != NULL)
		if (info->entry->d_name[0] != '.' || ft_strchr(a->arg, 'a') != NULL)
		{
			ft_getinfo(info->entry->d_name, &info->statbuf);
			addentry(&list, info->entry->d_name, dir);
		}
	ft_lstsort(&list, a->arg);
	tmp = list;
	while (tmp)
	{
		puts(tmp->name);
		s = ft_strjoin(tmp->dir, tmp->name);
		if (ft_isdir(0, s) && tmp->name[0] != '.')
		{
			rec[i] = s;
			i++;
		}
		tmp = tmp->next;
	}
	closedir(info->dp);

	

	puts("");
	j = -1;
	if (i > 0)
		if (ft_strchr(a->arg, 'R') != NULL)
			while (++j < i)
			{
				printf("%s\n", rec[j]);
				ft_read_curdir(rec[j], a, info);
			}
}


int					main(int ac, char **av)
{
	int				i;
	t_info			a;
	t_lst			*list = NULL;
	t_lst			*tmp;
	t_dir			dir_info;

	a.arg =	ft_strnew(100);
	a.line = ft_strnew(50);
	a.line[0] = '.';
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
			}
			else if (ft_isdir(0, av[i]))
				a.line = av[i];
		}
	}
	ft_read_curdir(a.line, &a,  &dir_info);
	return (0);
}

#include "ft_ls.h"

int			ft_isdir(int n, char *dir)
{
	if (n > 0)
		return (n >= 040000 && n <= 040777);
	if (dir != NULL)
	{
		if (opendir(dir) != NULL)
			return (1);
		else
			return (0);
	}
	return (0);
}

void		addentry(t_list **list, char *entry, char *directory, int spaces)
{
	t_list *temp;
	t_list *end;
	t_list *current;

	current = *list;
	
	temp = (t_list*)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->dir = directory;
	temp->data = entry;

	if ((*list) == NULL)
		*list = temp;
	else
	{
		while(current->next)
			current = current->next;
		current->next = temp;
	}
}

void		ft_printlist(t_list *list, t_info *a)
{
	if (ft_strchr(a->arg, 'r') != NULL)
		ft_lstsort(list, 'r');
	else if (ft_strchr(a->arg, 't') != NULL)
		ft_lstsort(list, 't');
	else
		ft_lstsort(list, 'a');
	while (list)
	{
		//puts((list->dir));
		printf("%*s%s ---- %i\n", (int)ft_strlen(list->dir), "", list->data, (int)ft_strlen(list->dir));
		list = list->next;
	}
}

void		ft_filllist(char *dir, int depth, t_info *a, t_list **list)
{
	DIR		*dp;
	struct	dirent *entry;
	struct	stat statbuf;
	int		spaces = depth * 4;
	char	*direc;

	if((dp = opendir(dir)) == NULL)
	{
		fprintf(stderr,"cannot open directory: %s\n", dir);
		return;
	}
	while((entry = readdir(dp)) != NULL)
	{
		if (entry->d_name[0] != '.' || ft_strchr(a->arg, 'a') != NULL)
		{	
			lstat(entry->d_name, &statbuf); //fills statbuf like mode
			if (ft_isdir(statbuf.st_mode, NULL))
			{
				direc = dir;
				direc = ft_strjoin(ft_strjoin(direc, "/"), entry->d_name);
				addentry(list, entry->d_name, direc, spaces);
				if (ft_strchr(a->arg, 'R') != NULL && entry->d_name[0] != '.' && ft_isdir(0, direc))
				{
					ft_filllist(direc, depth+1, a, list);
				}
			}
			else
			{
				addentry(list, entry->d_name, dir, spaces);
			}
		}
	}
	closedir(dp);
	ft_printlist(*list, a);
}

int			main(int ac, char **av)
{
	int		i;
	t_info	a;
	t_list	*list;

	a.arg =	ft_strnew(100);
	a.line = ft_strnew(50);
	a.line[0] = '.';
	if (ac > 1)
	{
		i = 0;
		while (++i != ac && i < 10)
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
	ft_filllist(a.line, 0 , &a, &list);
	return (0);
}

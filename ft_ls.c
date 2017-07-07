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

void		addentry(t_list **list, char *entry, char *directory, int spaces, t_list *branch)
{
	t_list *temp;
	t_list *end;
	t_list *current;

	current = *list;
	
	temp = (t_list*)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->branch = NULL; 
	temp->dir = directory;
	temp->data = entry;
	
	if ((*list) == NULL)
	{
		*list = temp;
	}
	else
	{
		while(current->next)
			current = current->next;
		current->next = temp;
	}
}

void		ft_printlist(t_list *list, t_info *a)
{
/*	
	if (ft_strchr(a->arg, 'r') != NULL)
		ft_lstsort(list, 'r');
	else if (ft_strchr(a->arg, 't') != NULL)
		ft_lstsort(list, 't');
	else
		ft_lstsort(list, 'a');
*/	
	t_list *start;

	start = list;	
	puts("");
	while (list)
	{
			printf("%s/%s\n", list->dir, list->data);
			list = list->next;
	}
	puts("");
	list = start;
	while (list)
	{
		if (list->branch != NULL)
		{
			puts("FOUND NEW BRANCH");
			ft_printlist(list->branch, a);
		}
		list = list->next;
	}
}

void		ft_filllist(char *dir, int depth, t_info *a, t_list **list)
{
	DIR		*dp;
	struct	dirent *entry;
	static struct	stat statbuf;
	int		spaces = depth * 4;
	char	*direc = NULL;

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
				if (direc == NULL && ft_strlen(dir) > 1)
				{
					direc = dir;
					*list = malloc(sizeof(t_list));
					(*list)->branch = malloc(sizeof(t_list));
					addentry(list, entry->d_name, direc, spaces, (*list)->branch);
					*list = (*list)->branch;
				}
				else
				{
					direc = dir;
					addentry(list, entry->d_name, direc, spaces, NULL);
				}
				direc = ft_strjoin(ft_strjoin(direc, "/"), entry->d_name);
				if (ft_strchr(a->arg, 'R') != NULL && entry->d_name[0] != '.' && ft_isdir(0, direc))
				{
					ft_filllist(direc, depth+1, a, &(*list)->branch);
				}
			}
			else
			{
				addentry(list, entry->d_name, dir, spaces, NULL);
			}
		}
	}
	closedir(dp);
}

int			main(int ac, char **av)
{
	int		i;
	t_info	a;
	t_list	*list;

	puts("_________________________________START______________________________\n");

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
	ft_printlist(list, &a);
	return (0);
}

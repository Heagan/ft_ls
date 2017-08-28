#include "lslib.h"

int						ft_isdir(int n, char *dir)
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

void					addentry(t_lst **list, char *entry, char *directory)
{
	t_lst 				*temp;
	t_lst 				*current;

	current = *list;

	temp = (t_lst *)malloc(sizeof(t_lst));
	temp->next = NULL;
	temp->branch = NULL; 
	temp->dir = directory;
	temp->data = entry;
	
	if (*list == NULL) /* is this the first element in the lst */
		*list = temp;	/*set temp as the beginning of the list */
	else
	{
		while(current->next) /* go to the end */
			current = current->next;
		current->next = temp; /* add temp to the end */
	}
}

void					ft_printlist(const t_lst *list, t_info *a)
{
	t_lst				*start;

	start = (t_lst *)list;
	if (start)
		if (start->dir != NULL)
			if (ft_strstr(start->dir, "./") != NULL)
				ft_printf(2, start->dir, "/");
	while (start)
	{
		ft_putstr(start->data);
		ft_putstr("\n");
		start = start->next;
	}
	puts("");
	start = (t_lst *)list;
	while (start)
	{
		if (start->branch != NULL)
			ft_printlist(start->branch, a);
		start = start->next;
	}
}

void					ft_filllist(char *dir, int depth, t_info *a, t_lst **list)
{
	DIR					*dp;
	struct dirent 		*entry;
	static struct stat	statbuf;
	int					spaces;
	char				*direc;

	direc = NULL;
	spaces = depth * 4;
	if((dp = opendir(dir)) == NULL)
	{
		fprintf(stderr,"cannot open directory: %s\n", dir);
		return;
	}

	while ((entry = readdir(dp)) != NULL) /* read contents */
	{
		puts(entry->d_name);
		if (entry->d_name[0] != '.' || ft_strchr(a->arg, 'a') != NULL) /* if we not doing all the files 'a' */
		{	
			lstat(entry->d_name, &statbuf); /* Save info */
			if (ft_isdir(statbuf.st_mode, NULL)) /* is dir? num test */
			{
				if (direc == NULL && ft_strlen(dir) > 1) /* has direc been set? */
				{
					direc = dir; /* set to current dir */
					addentry(list, entry->d_name, direc); /* add file name to list */
					*list = (*list)->branch; /* start adding stuff now onto the branch */
				}
				else
				{
					direc = dir; /* set to current dir <look at if statment>*/
					addentry(list, entry->d_name, direc); /* add file name to lst */
				}
				direc = ft_strjoin(ft_strjoin(direc, "/"), entry->d_name); /* either make the dir deeper or add the file name */
				if (ft_strchr(a->arg, 'R') && entry->d_name[0] != '.' && ft_isdir(0, direc))
					ft_filllist(direc, depth + 1, a, &(*list)->branch); /* RECURSE!! add onto the branch thou*/
			}
			else
				addentry(list, entry->d_name, dir); /* if not a dir just add the name to list */ 
		}
	}
	ft_lstsort(*list, a->arg);
	closedir(dp);
}

int					main(int ac, char **av)
{
	int				i;
	t_info			a;
	t_lst			*list;

	a.arg =	ft_strnew(100);
	a.line = ft_strnew(50);
	a.line[0] = '.'; /* set current path */
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
	ft_filllist(a.line, 0 , &a, &list);
	ft_printlist(list, &a);
	return (0);
}

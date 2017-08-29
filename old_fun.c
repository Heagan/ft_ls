
void					ft_filllistold(char *dir, int depth, t_info *a, t_lst **list)
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

	while ((entry = readdir(dp)) != NULL)
	{
		puts(entry->d_name);
		if (entry->d_name[0] != '.' || ft_strchr(a->arg, 'a') != NULL)
		{	
			lstat(entry->d_name, &statbuf);
			if (ft_isdir(statbuf.st_mode, NULL))
			{
				if (direc == NULL && ft_strlen(dir) > 1)
				{
					direc = dir;
					addentry(list, entry->d_name, direc); 
					*list = (*list)->branch; 
				}
				else
				{
					direc = dir;
					addentry(list, entry->d_name, direc); 
				}
				direc = ft_strjoin(ft_strjoin(direc, "/"), entry->d_name);
				if (ft_strchr(a->arg, 'R') && entry->d_name[0] != '.' && ft_isdir(0, direc))
					ft_filllist(direc, depth + 1, a, &(*list)->branch); 
			}
			else
				addentry(list, entry->d_name, dir); 
		}
	}
	ft_lstsort(*list, a->arg);
	closedir(dp);
}

/*
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
}*/
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

void					addentry(t_lst **list, char *name, char *directory, char *perm)
{
	t_lst 				*temp;
	t_lst 				*current;

	
	current = *list;

	temp = (t_lst *)malloc(sizeof(t_lst));
	temp->next = NULL; 
	temp->dir = ft_strjoin(directory, "/");
	temp->name = ft_strdup(name);
	temp->perm = ft_strdup(perm);
	
	if (*list == NULL)
		*list = temp;
	else
	{
		while(current->next)
			current = current->next;
		current->next = temp;
	}
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

char					*getcode(char n)
{
	char	*s;

	s = (char *)malloc(4);
	s[3] = '\0';
	n -= '0';
	if (n > 3)
		s[0] = 'r';
	else
		s[0] = '-';
	if ((n > 4 && n != 5) || n == 2)
		s[1] = 'w';
	else
		s[1] = '-';
	if ((n > 4 && n != 6) || n == 1)
		s[2] = 'x';
	else
		s[2] = '-';
	return (s);			
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

char		*ft_getinfo(char *entry, t_stat *statbuf, char *dir, t_dir *info)
{
	char	*perm;
	char	*tmp;

	lstat(entry, statbuf);
	perm = ft_strnew(10);
	bzero(perm, 10);
	
	dir = ft_strjoin(ft_strjoin(dir, "/"), entry);
	perm[0] = filetype(statbuf->st_mode);
	tmp = perm;	
 	perm = ft_strjoin(tmp, fileperm(statbuf->st_mode));
	printf("%s \n", statbuf->st_uid);
	return (perm);
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
			addentry(&list, info->entry->d_name, dir,
				ft_getinfo(info->entry->d_name, &info->statbuf, dir, info));
	ft_lstsort(&list, a->arg);
	tmp = list;
	while (tmp)
	{
		if (ft_strchr(a->arg, 'l') != NULL)
			printf("%s\t", tmp->perm);
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

	j = -1;
	if (i > 0)
		if (ft_strchr(a->arg, 'R') != NULL)
		{
			while (++j < i)
			{
				puts("");
				printf("%s\n", rec[j]);
				ft_read_curdir(rec[j], a, info);
			}
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

#include "lslib.h"

void					addentry(t_lst **list, t_dir *info, char *directory, char *perm)
{
	t_lst 				*temp;
	t_lst 				*current;

	current = *list;
	temp = (t_lst *)malloc(sizeof(t_lst));
	temp->next = NULL; 
	temp->dir = ft_strjoin(directory, "/");
	temp->name = ft_strdup(info->entry->d_name);
	temp->time = info->statbuf.st_mtime;
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
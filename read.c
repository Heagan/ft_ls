#include "lslib.h"

static void        recurse(char *dir, t_info *a, t_dir *info, t_read *r)
{
    r->j = -1;
	if (r->i > 0)
		if (ft_strchr(a->arg, 'R') != NULL)
		{
			while (++r->j < r->i)
			{
				ft_putendl("");
				ft_putendl(r->rec[r->j]);
				info->b_size = 0;
				info->tabs = 1;
				info->len = 6;
				ft_read_curdir(r->rec[r->j], a, info, r);
			}
		}
}

static void             ft_print(char *dir, t_info *a, t_dir *info, t_read *r )
{

    r->tmp = r->list;
	if (ft_strchr(a->arg, 'l') != NULL)
		ft_printf(3, "Total: ", ft_itoa(info->b_size), "\n");
	while (r->tmp)
	{
		if (ft_strchr(a->arg, 'l') != NULL)
			ft_printf(2, r->tmp->perm, " ");
		ft_putendl(r->tmp->name);
		r->s = ft_strjoin(r->tmp->dir, r->tmp->name);
		if (ft_isdir(0, r->s) && r->tmp->name[0] != '.')
		{
			r->rec[r->i] = r->s;
			r->i++;
		}
		r->tmp = r->tmp->next;
	}
    closedir(info->dp);
}

static void         ft_save(char *dir, t_info *a, t_dir *info, t_read *r)
{
    r->list  = NULL;
    while ((info->entry = readdir(info->dp)) != NULL)
    if (info->entry->d_name[0] != '.' || ft_strchr(a->arg, 'a') != NULL)
    {
        r->stmp = ft_getinfo(info, &info->statbuf, dir);
         if (ft_strcmp("inc", r->stmp) != 0)
             addentry(&r->list, info, dir, r->stmp);
        else
           return (ft_read_curdir(dir, a, info, r));
         info->b_size += info->statbuf.st_blocks;
    }
}

char					*ft_read_curdir(char *dir, t_info *a, t_dir *info, t_read *r)
{
    r->list = NULL;
	if ((info->dp = opendir(dir)) == NULL)
	{
		ft_printf(3, "Cant open dir ", dir, "");
		return ;
    }
    puts("SEG 1");
    r->list = ft_save(dir, a, info, r);
    puts("SEG 2");
    ft_lstsort(&r->list, a->arg);
    puts("SEG 3");
    ft_print(dir, a, info, r);    
    puts("SEG 4");
    recurse(dir, a, info, r);
    puts("SEG 5");
}
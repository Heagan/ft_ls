/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:05:38 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/05 09:53:11 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lslib.h"

static void			recurse(t_info *a, t_read *r)
{
	r->j = -1;
	if (r->i > 0)
		if (ft_strchr(a->arg, 'R') != NULL)
			while (++r->j < r->i)
			{
				ft_putendl("");
				ft_putendl(r->rec[r->j]);
				ft_read_curdir(r->rec[r->j], a);
			}
}

static void			ft_print(t_info *a, t_dir *info, t_read *r)
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
		if (!(r->tmp->perm[0] == 'l'))
			if (ft_isdir(0, r->s))
				if (ft_strcmp(r->tmp->name, ".") != 0
						&& ft_strstr(r->tmp->name, "..") == NULL)
				{
					r->rec[r->i] = r->s;
					r->i++;
				}
		r->tmp = r->tmp->next;
	}
	closedir(info->dp);
}

static void			*ft_save(char *dir, t_info *a, t_dir *info, t_read *r)
{
	while ((info->entry = readdir(info->dp)) != NULL)
		if (info->entry->d_name[0] != '.' || ft_strchr(a->arg, 'a') != NULL)
		{
			r->stmp = ft_getinfo(info, &info->statbuf, dir);
			addentry(&r->list, info, dir, r->stmp);
			info->b_size += info->statbuf.st_blocks;
		}
	return (NULL);
}

static void			prepvar(t_dir *info)
{
	info->b_size = 0;
	info->tabs = 1;
	info->len = 6;
}

void				*ft_read_curdir(char *dir, t_info *a)
{
	t_read			r;
	t_dir			info;

	r.i = 0;
	r.list = NULL;
	prepvar(&info);
	if ((info.dp = opendir(dir)) == NULL)
	{
		ft_printf(3, "Cant open dir ", dir, "");
		return (NULL);
	}
	ft_save(dir, a, &info, &r);
	ft_lstsort(&r.list, a->arg);
	ft_print(a, &info, &r);
	recurse(a, &r);
	return (NULL);
}

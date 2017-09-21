/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:10:15 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/04 08:34:32 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lslib.h"

static	void	ft_lstswap(t_lst *lst, t_lst *mst)
{
	const void	*tmp;
	const void	*tmpd;
	const void	*tmpp;
	int			tmpt;

	tmp = lst->name;
	tmpp = lst->perm;
	tmpd = lst->dir;
	tmpt = lst->time;
	lst->name = mst->name;
	lst->dir = mst->dir;
	lst->perm = mst->perm;
	lst->time = mst->time;
	mst->name = (void *)tmp;
	mst->dir = (void *)tmpd;
	mst->perm = (void *)tmpp;
	mst->time = tmpt;
}

void			ft_lsttimesort(t_lst **list, int sign)
{
	t_lst		*head;
	t_lst		*tmp;
	int			b;

	head = *list;
	if (head == NULL)
		return ;
	b = 1;
	while (b)
	{
		b = 0;
		tmp = head;
		while (tmp->next)
		{
			if (lstcmp_time(tmp, tmp->next, sign))
			{
				ft_lstswap(tmp, tmp->next);
				b = 1;
			}
			tmp = tmp->next;
		}
	}
}

static void		lst_timer(t_lst **list, char *arg)
{
	if (ft_strchr(arg, 't') != NULL)
	{
		if (ft_strchr(arg, 'r') == NULL)
			ft_lsttimesort(list, 1);
		else
			ft_lsttimesort(list, 0);
	}
}

static int		lst_reverse(t_lst *tmp, char *arg)
{
	int b;

	b = 0;
	if (ft_strchr(arg, 'r') == NULL)
	{
		if (lstcmp_asending(tmp, tmp->next))
		{
			ft_lstswap(tmp, tmp->next);
			b = 1;
		}
	}
	else if (lstcmp_desending(tmp, tmp->next))
	{
		ft_lstswap(tmp, tmp->next);
		b = 1;
	}
	return (b);
}

void			ft_lstsort(t_lst **list, char *arg)
{
	t_lst		*head;
	t_lst		*tmp;
	int			b;

	head = *list;
	if (head == NULL)
		return ;
	b = 1;
	while (b)
	{
		b = 0;
		tmp = head;
		while (tmp->next)
		{
			b += lst_reverse(tmp, arg);
			tmp = tmp->next;
		}
	}
	lst_timer(list, arg);
}

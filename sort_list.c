#include "lslib.h"

const size_t	ft_lstsize(const t_lst *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

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

int				lstcmp_asending(t_lst *l1, t_lst *l2)
{
	if (ft_strcmp(l1->name, l2->name) < 0)
		return (0);
	return (1);
}

int				lstcmp_desending(t_lst *l1, t_lst *l2)
{
	if (ft_strcmp(l1->name, l2->name) > 0)
		return (0);
	return (1);
}

int				lstcmp_time(t_lst *l1, t_lst *l2, int sign)
{
	if (sign)
		return (l1->time < l2->time);
	return (l1->time > l2->time);
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
			if (ft_strchr(arg, 'r') == NULL)
			{
				if (lstcmp_asending(tmp, tmp->next))
				{
					ft_lstswap(tmp, tmp->next);
					b = 1;
				}
			}
			else 
				if (lstcmp_desending(tmp, tmp->next))
				{
					ft_lstswap(tmp, tmp->next);
					b = 1;
				}
			tmp = tmp->next;
		}
	}
	if (ft_strchr(arg, 't' ) != NULL)
	{	
		if (ft_strchr(arg, 'r') == NULL)
			ft_lsttimesort(list, 1);
		else
			ft_lsttimesort(list, 0);
	}
}

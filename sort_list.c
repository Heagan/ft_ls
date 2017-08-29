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

	tmp = lst->name;
	tmpd = lst->dir;
	lst->name = mst->name;
	lst->dir = mst->dir;
	mst->name = (void *)tmp;
	mst->dir = (void *)tmpd;
}

int				lstcmp_asending(t_lst *l1, t_lst *l2)
{
	if (ft_strccmp(l1->name, l2->name) < 0)
		return (0);
	return (1);
}

int				lstcmp_desending(t_lst *l1, t_lst *l2)
{
	if (ft_strccmp(l1->name, l2->name) > 0)
		return (0);
	return (1);
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
}

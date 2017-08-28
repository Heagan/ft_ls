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

	tmp = lst->data;
	tmpd = lst->dir;
	lst->data = mst->data;
	lst->dir = mst->dir;
	mst->data = (void *)tmp;
	mst->dir = (void *)tmpd;
}

int				lstcmp_asending(t_lst *l1, t_lst *l2)
{
	if (ft_strcmp(l1->data, l2->data) < 0)
		return (0);
	return (1);
}

int				lstcmp_desending(t_lst *l1, t_lst *l2)
{
	if (ft_strcmp(l1->data, l2->data) > 0)
		return (0);
	return (1);
}

void			ft_lstsort(const t_lst *list, char *arg)
{
	t_lst		*head;
	int			b;

	b = 1;
	while (b)
	{
		b = 0;
		head = (t_lst *)list;
		while (head->next)
		{
			if (ft_strchr(arg, 'r') == NULL)
			{
				if (lstcmp_asending(head, head->next))
				{
					ft_lstswap(head, head->next);
					b = 1;
				}
			}
			else
			if (lstcmp_desending(head, head->next))
			{
				ft_lstswap(head, head->next);
				b = 1;
			}
			head = head->next;
		}
	}
}

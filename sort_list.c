#include "ft_ls.h"

size_t	ft_lstsize(const t_list *lst)
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

static	void	ft_lstswap(t_list *lst, t_list *mst)
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


void	ft_lstsort(t_list *lst, char arg)
{
	size_t	i;
	t_list	*l;
	size_t	size;
	size_t	newsize;
	char	*c_dir;

	size = ft_lstsize(lst);
	newsize = size;
	while (newsize)
	{
		i = 1;
		l = lst;
		newsize = 0;
		while (i < size)
		{
			if (arg == 'a')
				if (ft_strcmp(l->dir, l->next->dir) > 0)
				{
					ft_lstswap(l, l->next);
					newsize = i;
				}
			if (arg == 'r')
				if (ft_strcmp(l->dir, l->next->dir) < 0)
				{
					ft_lstswap(l, l->next);
					newsize = i;
				}
			l = l->next;
			i++;
		}
		size = newsize;
	}
}

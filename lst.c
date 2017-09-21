/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:17:31 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/05 09:53:43 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lslib.h"

size_t			ft_lstsize(const t_lst *lst)
{
	size_t		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
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

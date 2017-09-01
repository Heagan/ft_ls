/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:25:51 by gsferopo          #+#    #+#             */
/*   Updated: 2017/07/17 14:59:49 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_realloc(void **obj, int oldlen, int new_size)
{
	void	*temp;

	temp = (void *)malloc(sizeof(void *) * new_size);
	if (temp == NULL)
		return (-1);
	ft_memcpy(temp, *obj, oldlen);
	free(*obj);
	*obj = temp;
	return (1);
}

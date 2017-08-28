/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:17:40 by gsferopo          #+#    #+#             */
/*   Updated: 2017/08/14 16:20:09 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			num_len(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_hex(int n)
{
	char	*tab;
	char	*s;
	int		i;
	int		len;

	tab = "0123456789ABCDEF";
	len = num_len(n);
	s = (char *)malloc(len + 1);
	i = 0;
	while (n != 0)
	{
		s[i] += tab[n % 16];
		n /= 16;
		i++;
	}
	return (s);
}

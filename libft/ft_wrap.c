/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 12:59:58 by gsferopo          #+#    #+#             */
/*   Updated: 2017/07/17 15:46:29 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_wrap(int min, int max, int n)
{
	int		b;

	if (min > max)
	{
		b = min;
		min = max;
		max = b;
	}
	b = 1;
	while (b)
	{
		if (n > max)
			n = min + (n - max - 1);
		else if (n < min)
			n = max - (n + min + 1);
		else
			b = 0;
	}
	return (n);
}

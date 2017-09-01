/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:51:43 by gsferopo          #+#    #+#             */
/*   Updated: 2017/07/17 15:46:32 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				buff_refill(char *buff, int fd)
{
	ft_bzero(buff, BUFF_SIZE + 1);
	return (read(fd, buff, BUFF_SIZE));
}

static int				line_len(char *buff, size_t index)
{
	size_t				len;

	len = 0;
	while (buff[index] != '\n' && index < BUFF_SIZE)
	{
		len++;
		index++;
	}
	return (len);
}

static int				prep(char *b, size_t fd, size_t *i, size_t *p_fd)
{
	if (*p_fd != fd)
	{
		*p_fd = fd;
		*i = 0;
		return (buff_refill(b, fd));
	}
	else
	{
		if (b[*i] == '\n')
			(*i)++;
		return (BUFF_SIZE);
	}
}

static int				line_fill(char **l, char *b, size_t *bix, size_t *lix)
{
	while (b[*bix] != '\n' && *bix < BUFF_SIZE)
	{
		(*l)[(*lix)++] = b[(*bix)++];
	}
	(*l)[(*lix)] = '\0';
	if (b[*bix] == '\n')
		return (1);
	else
		return (0);
}

int						get_next_line(const int fd, char **line)
{
	size_t				index;
	int					count;
	int					oldlen;
	int					len;
	static	t_buff_info bi = {.fd = -100};

	count = prep(bi.buff, fd, &(bi.index), &(bi.fd));
	if (count == -1 || (index = 0 == 1))
		return (-1);
	len = line_len(bi.buff, bi.index) + 1;
	oldlen = len;
	if (line == NULL || ((*line = ft_strnew(len)) == NULL))
		return (-1);
	while ((line_fill(line, bi.buff, &(bi.index), &index) == 0))
	{
		count = buff_refill(bi.buff, fd);
		len += line_len(bi.buff, bi.index = 0);
		if (ft_realloc((void **)line, oldlen, len) == -1)
			return (-1);
		if ((count == 0 && *line[0] == '\0') || ((oldlen = len) == -10))
			return (0);
		else if (count == 0)
			return (1);
	}
	return (1);
}

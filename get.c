/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 07:58:41 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/04 08:02:42 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lslib.h"

char				*getcode(char n)
{
	char			*s;

	s = (char *)malloc(4);
	s[3] = '\0';
	n -= '0';
	if (n > 3)
		s[0] = 'r';
	else
		s[0] = '-';
	if ((n > 4 && n != 5) || n == 2)
		s[1] = 'w';
	else
		s[1] = '-';
	if ((n > 4 && n != 6) || n == 1)
		s[2] = 'x';
	else
		s[2] = '-';
	return (s);
}

char				*get_uid(int uid)
{
	struct passwd	*pwd;

	if ((pwd = getpwuid(uid)) != NULL)
		return (pwd->pw_name);
	else
		return (ft_itoa(uid));
}

char				*get_gid(int gid)
{
	struct group	*grp;

	if ((grp = getgrgid(gid)) != NULL)
		return (grp->gr_name);
	else
		return (NULL);
}

char				*get_time(time_t rawtime)
{
	char			*rtime;

	rtime = ctime(&rawtime);
	rtime = ft_strdup(rtime + 4);
	rtime[ft_strlen(rtime) - 9] = '\0';
	return (ft_strdup(rtime));
}

char				*get_tabs(t_dir *info, int len)
{
	int				i;
	char			*s;

	s = ft_strnew(1);
	s[0] = ' ';
	i = 0;
	while (i < info->len - len + 1)
	{
		s = ft_strjoin(s, " ");
		i += 1;
	}
	if (len == 100)
	{
		s[0] = '\t';
		s[1] = '\t';
	}
	return (s);
}

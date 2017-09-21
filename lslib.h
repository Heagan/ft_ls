/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:29:03 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/04 08:31:58 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSLIB_H
# define LSLIB_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# include "libft/libft.h"

typedef struct dirent	t_dirt;
typedef struct stat		t_stat;

typedef struct			s_line_info
{
	char				*line;
	char				*arg;
	int					i;
}						t_info;

typedef struct			s_directory
{
	DIR					*dp;
	t_dirt				*entry;
	t_stat				statbuf;
	long long int		b_size;
	int					tabs;
	int					len;
	char				*perm;
	char				*tmp;
}						t_dir;

typedef struct			s_lst
{
	char				*name;
	char				*dir;
	char				*perm;
	t_dirt				*entry;
	int					time;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_read
{
	t_lst				*list;
	char				*stmp;
	t_lst				*tmp;
	char				*s;
	char				*rec[255];
	int					i;
	int					j;
}						t_read;

void					*ft_read_curdir(char *dir, t_info *a);
void					ft_lstsort(t_lst **list, char *arg);
char					*get_tabs(t_dir *info, int len);
char					*get_time(time_t rawtime);
char					*get_gid(int gid);
char					*get_uid(int uid);
char					*getcode(char n);
int						ft_islink(int n);
int						ft_isdir(int n, char *dir);
char					filetype(int n);
char					*fileperm(int n);
void					addentry(t_lst **list, t_dir *info, char *directory,
		char *perm);
char					*ft_getinfo(t_dir *info, t_stat *statbuf, char *dir);
size_t					ft_lstsize(const t_lst *lst);
int						lstcmp_asending(t_lst *l1, t_lst *l2);
int						lstcmp_desending(t_lst *l1, t_lst *l2);
int						lstcmp_time(t_lst *l1, t_lst *l2, int sign);

#endif

#ifndef FT_LS_H
# define FT_LS_H

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

typedef struct		s_line_info 
{
	char			*line;
	char			*arg;
	int				i;
}					t_info;

typedef struct		s_directory
{
	DIR				*dp;
	t_dirt		 	*entry;
	t_stat			statbuf;
	long long int	b_size;
	int				tabs;
	int				len;
	char			*perm;
	char			*tmp;
}					t_dir;

typedef struct		s_lst
{
	char			*name;
	char			*dir;
	char			*perm;
	t_dirt		 	*entry;
	int				time;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_read
{
	t_lst 		*list;
	char    	*stmp;
	t_lst	    *tmp;
	char    	*s;
	char        *rec[255];
	int		    i;
	int			j;	
}					t_read;

char	*ft_read_curdir(char *dir, t_info *a);

void	ft_lstsort(t_lst **list, char *arg);
int		ft_strccmp(const char *s1, const char *s2);

/* get.c */
char		*get_tabs(t_dir *info, int len);
char		*get_time(time_t rawtime);
char		*get_gid(int gid);
char		*get_uid(int uid);
char		*getcode(char n);

/* file */
int			ft_islink(int n);
int			ft_isdir(int n, char *dir);
char		filetype(int n);
char		*fileperm(int n);

void		addentry(t_lst **list, t_dir *info, char *directory, char *perm);
char		*ft_getinfo(t_dir *info, t_stat *statbuf, char *dir);

#endif

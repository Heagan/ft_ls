#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# include "libft.h"

typedef struct dirent	t_dirt;
typedef struct stat		t_stat;

typedef struct		s_line_info 
{
	char			*line;
	char			*arg;

}					t_info;
/*
typedef struct		s_directory
{
	char			*name;
	char			*dir;
	int				*spaces;
	
}					t_dir;*/

typedef struct		s_directory
{
	DIR				*dp;
	t_dirt		 	*entry;
	t_stat			statbuf;
}					t_dir;

typedef struct		s_lst
{
	char			*name;
	char			*dir;
	t_dirt		 	*entry;
	struct s_lst	*next;
}					t_lst;

void	ft_lstsort(t_lst **list, char *arg);
int		ft_strccmp(const char *s1, const char *s2);

#endif

#ifndef FT_LS_H
# define FT_LS_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "libft.h"

typedef struct		s_line_info 
{
	char			*line;
	char			*arg;

}					t_info;

typedef struct		s_directory
{
	char			*name;
	char			*dir;
	int				*spaces;
	
}					t_dir;

typedef struct		s_list
{
	char			*data;
	char			*dir;
	struct s_list	*branch;
	struct s_list	*next;
}					t_list;

void				ft_lstsort(t_list *lst, char arg);

#endif

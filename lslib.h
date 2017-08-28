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

typedef struct		s_lst
{
	char			*data;
	char			*dir;
	struct s_lst	*branch;
	struct s_lst	*next;
}					t_lst;

void	ft_lstsort(const t_lst *list, char *arg);

#endif

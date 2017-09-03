#include "lslib.h"

static char        *getinfoex(t_dir *info, t_stat *statbuf, char *dir)
{
	struct passwd	*pwd;
    struct group	*grp;
    
	info->perm = ft_strjoin(info->perm, info->tmp);
	info->perm = ft_strjoin(info->perm, get_tabs(info, ft_strlen(info->tmp)));
	info->tmp = get_gid(statbuf->st_gid);
	info->perm = ft_strjoin(info->perm, info->tmp);
	info->tmp  = ft_strjoin(ft_itoa(statbuf->st_size), " ");
	info->tmp  = ft_strjoin(info->tmp, get_time(statbuf->st_mtime));
	info->perm = ft_strjoin(info->perm, get_tabs(info, ft_strlen(get_gid(statbuf->st_gid))));
	info->perm = ft_strjoin(info->perm, info->tmp);
	return (info->perm);
}

char                *ft_getinfo(t_dir *info, t_stat *statbuf, char *dir)
{
	struct passwd	*pwd;
	struct group	*grp;

	dir = ft_strjoin(ft_strjoin(dir, "/"), info->entry->d_name);
	lstat(dir, statbuf);
	info->perm = ft_strnew(1);
	info->perm[0] = filetype(statbuf->st_mode);
 	info->perm = ft_strjoin(info->perm, fileperm(statbuf->st_mode));
	info->perm = ft_strjoin(info->perm, " ");
	info->perm = ft_strjoin(info->perm, ft_itoa(statbuf->st_nlink));
 	info->perm = ft_strjoin(info->perm, " ");
	info->tmp = get_uid(statbuf->st_uid);
	if (info->len < ft_strlen(info->tmp))
	{
		info->len = ft_strlen(info->tmp);
		return ("inc");
    }
    return (getinfoex(info, statbuf, dir));
}



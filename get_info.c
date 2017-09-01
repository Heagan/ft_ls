#include "lslib.h"

static char        *getinfoex(t_dir *info, t_stat *statbuf, char *dir)
{
    char			*perm;
	char			*tmp;
	struct passwd	*pwd;
    struct group	*grp;
    
	perm = ft_strjoin(perm, tmp);
	perm = ft_strjoin(perm, get_tabs(info, ft_strlen(tmp)));
	tmp = get_gid(statbuf->st_gid);
	perm = ft_strjoin(perm, tmp);
	tmp  = ft_strjoin(ft_itoa(statbuf->st_size), " ");
	tmp  = ft_strjoin(tmp, get_time(statbuf->st_mtime));
	perm = ft_strjoin(perm, get_tabs(info, ft_strlen(get_gid(statbuf->st_gid))));
	perm = ft_strjoin(perm, tmp);
	return (perm);
}

char                *ft_getinfo(t_dir *info, t_stat *statbuf, char *dir)
{
	char			*perm;
	char			*tmp;
	struct passwd	*pwd;
	struct group	*grp;

	dir = ft_strjoin(ft_strjoin(dir, "/"), info->entry->d_name);
	lstat(dir, statbuf);
	perm = ft_strnew(1);
	perm[0] = filetype(statbuf->st_mode);
 	perm = ft_strjoin(perm, fileperm(statbuf->st_mode));
	perm = ft_strjoin(perm, " ");
	perm = ft_strjoin(perm, ft_itoa(statbuf->st_nlink));
 	perm = ft_strjoin(perm, " ");
	tmp = get_uid(statbuf->st_uid);
	if (info->len < ft_strlen(tmp))
	{
		info->len = ft_strlen(tmp);
		return ("inc");
    }
    return (getinfoex(info, statbuf, dir));
}



#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

void listdir(const char *name, int indent)
{
	DIR *dir;
	struct dirent *entry;

	if (!(dir = opendir(name)))
		return;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_DIR) {
			char path[1024];
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
			printf("%*s[%s]\n", indent, "", entry->d_name);
			listdir(path, indent + 2);
		} else {
			printf("%*s %s\n", indent, "", entry->d_name);
		}
	}
	closedir(dir);
}


int		t_param(char *arg) //translate parameter
{
	if (arg[0] == '-')
		puts("-arg found!");
		return (1);
}

int		main(int ac, char **av)
{
	int	i;

	i = ac + 1;
	while (--i > 0)
		t_param((char *)av[i - 1]);
	listdir(".", 0);
}

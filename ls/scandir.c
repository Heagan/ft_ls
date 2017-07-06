#include <stdlib.h>
#include <stdio.h>
#define _SVID_SOURCE
/* print files in current directory in reverse order */
#include <dirent.h>

int		main(void)
{
	struct	dirent **namelist;
	int	n;

	n = scandir(".", &namelist, NULL, alphasort);
	if (n < 0)
		perror("scandir");
	else {
		while (n--) {
			printf("%s\n", namelist[n]->d_name);
			free(namelist[n]);
		}
		free(namelist);
	}
}

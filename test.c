#define  _POSIX_C_SOURCE 200809L
#define  _ATFILE_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>

static void my_print(const char *name, const struct stat *info)
{
	/* TODO: Better output; use info too, for 'ls -l' -style output? */
	printf("%s\n", name);
}

static int my_filter(const struct dirent *ent)
{
	/* Skip entries that begin with '.' */
	if (ent->d_name[0] == '.')
		return 0;

	/* Include all others */
	return 1;
}

static int my_ls(const char *dir)
{
	struct dirent **list = NULL;
	struct stat     info;
	DIR            *dirhandle;
	int             size, i, fd;

	size = scandir(dir, &list, my_filter, alphasort);
	if (size == -1) {
		const int cause = errno;

		/* Is dir not a directory, but a single entry perhaps? */
		if (cause == ENOTDIR && lstat(dir, &info) == 0) {
			my_print(dir, &info);
			return 0;
		}

		/* Print out the original error and fail. */
		fprintf(stderr, "%s: %s.\n", dir, strerror(cause));
		return -1;
	}

	/* We need the directory handle for fstatat(). */
	dirhandle = opendir(dir);
	if (!dirhandle) {
		/* Print a warning, but continue. */
		fprintf(stderr, "%s: %s\n", dir, strerror(errno));
		fd = AT_FDCWD;
	} else {
		fd = dirfd(dirhandle);
	}

	for (i = 0; i < size; i++) {
		struct dirent *ent = list[i];

		/* Try to get information on ent. If fails, clear the structure. */
		if (fstatat(fd, ent->d_name, &info, AT_SYMLINK_NOFOLLOW) == -1) {
			/* Print a warning about it. */
			fprintf(stderr, "%s: %s.\n", ent->d_name, strerror(errno));
			memset(&info, 0, sizeof info);
		}

		/* Describe 'ent'. */
		my_print(ent->d_name, &info);
	}

	/* Release the directory handle. */
	if (dirhandle)
		closedir(dirhandle);

	/* Discard list. */
	for (i = 0; i < size; i++)
		free(list[i]);
	free(list);

	return 0;
}

int main(int argc, char *argv[])
{
	int arg;

	setlocale(LC_ALL, "");

	if (argc > 1) {
		for (arg = 1; arg < argc; arg++) {
			if (my_ls(argv[arg])) {
				return EXIT_FAILURE;
			}
		}
	} else {
		if (my_ls(".")) {
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

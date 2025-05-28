#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

extern int errno;

int	main(int argc, char *argv[])
{
	int	fd;
	char *content;
	int i = 1;

	(void)argc;
	(void)argv;
	fd = open("normal.txt", O_RDONLY);
	if (fd == -1)
	{
		// Print the numeric error code set by the last failed system call
		printf("Error number: %d\n", errno);
		// Print the human-readable error message for the current errno value
		printf("Error message: %s\n", strerror(errno));
		return (-1);
	}
	else
	{
		while (content != NULL)
		{
			content = get_next_line(fd);
			printf("%d: %s", i++, content);
			fflush(stdout);
			free (content);
		}
	}
	close(fd);
}
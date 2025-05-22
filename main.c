#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

extern int errno;

int	main(void)
{
	int	fd;
	char *content;

	fd = open("empty.txt", O_RDONLY);
	if (fd == -1)
	{
		// Print the numeric error code set by the last failed system call
		printf("Error number: %d\n", errno);
		// Print the human-readable error message for the current errno value
		printf("Error message: %s\n", strerror(errno));
	}
	else
	{
		while (content)
		{
			content = get_next_line(fd);
			printf("%s\n", content);
		}
	}
	close(fd);
}
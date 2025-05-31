#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int	main(int argc, char *argv[])
{
	int	fd;
	int	i = 1;
	char *content = "ab";
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			fprintf(stderr, "open error");
			return (-1);
		}
	}
	else
	{
		fd = 0;
	}
	while (content != NULL)
	{
		content = get_next_line(fd);
		printf(" fd%d ----%d call: %s", fd, i++, content);
		free(content);
	}
	if (argc == 2)
		close(fd);
}
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	*content;

	i = 1;
	content = "ab";
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

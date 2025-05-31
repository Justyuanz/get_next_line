#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int	main(void)
{
	int	fd;
	int	i = 1;
	char *content = "ab";
	
	fd = open("testfiles/normal.txt", O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "open error");
		return (-1);
	}
	while (content != NULL)
	{
		content = get_next_line(fd);
		printf(" fd%d ----%d call: %s", fd, i++, content);
		free(content);
	}
	close(fd);
}
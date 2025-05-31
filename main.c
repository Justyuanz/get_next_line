#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
 int fd_done(char *content, int argc);

int	main(int argc, char *argv[])
{
	int	fd[1024] = {0};
	char *content = "ab";
	int	b = 0;
	int i = 0;
	int	j = 1;

	if (argc >= 2)
	{
		while (j < argc)
		{
			fd[i] = open(argv[j], O_RDONLY);
			if (fd[i] == -1)
				return (-1);
			i++;
			j++;
		}
		i = 0;
		while (fd_done(content, argc) != 1)
		{
			i = 0;
			while (i < argc - 1)
			{
				content = get_next_line (fd[i]);
				printf("fd%d:--%s",fd[i], content);
				fflush(stdout);
				if (!content)
					printf("\n");
				free(content);
				i++;
			}
		}
		while (i--)
			close (fd[i]);

	}
}
 int fd_done(char *content, int argc)
 {
	int i = 0;

	while (i < argc - 1)
	{
		if (content != NULL)
			return (0);
		i++;
	}
	return (1);
 }

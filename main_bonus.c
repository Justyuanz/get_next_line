#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	fd_alldone(int *flag, int argc);
int	should_print_or_not(int flag);

int	main(int argc, char *argv[])
{
	char	*content;
	int		fd[1024] = {0};
	int		flag[1024] = {0};
	int		b;
	int		i;

	content = "ab";
	b = 0;
	i = 0;
	if (argc >= 2)
	{
		while (i < argc - 1)
		{
			fd[i] = open(argv[i + 1], O_RDONLY);
			if (fd[i] == -1)
				return (-1);
			i++;
		}
		i = 0;
		while (fd_alldone(flag, argc) != 1)
		{
			i = 0;
			while (i < argc - 1)
			{
				content = get_next_line(fd[i]);
				if (!content)
					flag[i]++;
				if (should_print_or_not(flag[i]))
					printf("fd%d:%s", fd[i], content);
				fflush(stdout);
				if (!content)
					printf("\n");
				free(content);
				i++;
			}
			printf("-------end of one loop----------\n");
		}
		while (i--)
			close(fd[i]);
	}
}
int	fd_alldone(int *flag, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (flag[i] == 0) // not done yet
			return (0);
		i++;
	}
	return (1);
}

int	should_print_or_not(int flag)
{
	if (flag < 2)
		return (1);
	else
		return (0);
}

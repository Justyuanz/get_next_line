/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/26 17:00:35 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//ssize_t read(int fd, void *buf, size_t count)
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*newline;
	ssize_t	bytes_read;
	int	nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = malloc(1);
	newline[0] = '\0';
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		nl = gnl_find_nl(buf);
		newline = gnl_strjoin(newline, buf, nl);
		if (bytes_read == 0 || nl != -1)
			return (newline);
	}
	return (NULL);
}

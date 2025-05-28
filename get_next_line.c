/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/28 17:22:00 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 //ssize_t read(int fd, void *buf, size_t count)
 char	*get_next_line(int fd)
 {
 	int	nl;
 	int i;
 	char	*line;
 	ssize_t	bytes_read;
 	static char	buf[BUFFER_SIZE + 1];

 	i = 0;
 	if (fd < 0 || BUFFER_SIZE <= 0)
 		return (NULL);
 	line = malloc(1);
		if(!line)
			return (NULL);
 	line[0] = '\0';
	bytes_read = -1;
	nl = gnl_find_nl(buf, '\n');
	gnl_updatebuf(buf, nl);

	while (1)
 	{
		if (nl == -1)
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read < 0)
 				return (NULL);
		}
		buf[bytes_read] = '\0';
 		nl = gnl_find_nl(buf, '\n');
		line = gnl_strjoin(line, buf, nl);
		if (nl != -1)
			break;
		if (bytes_read == 0)
		{
			if (*buf)
			{
				line = buf;
				return (line);
			}
			return (NULL);
		}
 	}

 	return (line);
}

void gnl_updatebuf(char *buf,int nl)
{
	int	i;

	i = 0;
	if (nl != -1 && (buf[nl +1] || buf[nl]))
	{
		while (buf[i])
		{
			buf[i] = buf[nl + i + 1];
			i++;
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/27 20:14:47 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ssize_t read(int fd, void *buf, size_t count)
char	*get_next_line(int fd)
{	
	int	nl;
	char	*line;
	ssize_t	bytes_read;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	line[0] = '\0';	
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read)
	{
		if (bytes_read < 0)
			return (NULL);
		nl = gnl_find_nl(buf);
		if (nl != -1 && )
			line = gnl_strjoin(line, buf, nl);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		return (line);
		//somthing still in buf && there was nl
		// line 
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/29 23:54:56 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 char	*get_next_line(int fd)
 {
	t_gnl	gnl;
	static char	buf[BUFFER_SIZE + 1];

	gnl.line = malloc(1);
 	if (fd < 0 || BUFFER_SIZE <= 0 ||!gnl.line)
 		return (NULL);
 	gnl.line[0] = '\0';
	gnl_updatebuf(buf);
	while (1)
 	{
		if (gnl.nl == -1)
		{
			gnl.bytes_read = read(fd, buf, BUFFER_SIZE);
			if (gnl.bytes_read <= 0)
				return(gnl_error_eof(&gnl, buf));
			buf[gnl.bytes_read] = '\0';
		}
 		gnl.nl = gnl_find_nl(buf, '\n');
		gnl.line = gnl_strjoin(gnl.line, buf, gnl.nl);
		if (gnl.nl != -1)
			break;
 	}
 	return (gnl.line);
}

char *gnl_error_eof(t_gnl *gnl, char *buf)
{
	if (*buf)
	{
		buf[0] = '\0';
		return (gnl->line);
	}
 	gnl_free(&gnl->line);
	return (NULL);
}

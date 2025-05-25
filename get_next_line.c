/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/25 16:17:35 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//ssize_t read(int fd, void *buf, size_t count)
char	*get_next_line(int fd)
{
	char	*theline;
	char	*buf;
	char	*joinline;
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (!gnl_find_nl(buf))
		 	joinline = gnl_strjoin(,);//do something
		if (gnl_find_nl(buf))
			//do something
			return (theline);
		if (bytes_read == 0)
			break;
	}
	return (NULL);
}

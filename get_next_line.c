/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/23 16:15:37 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//ssize_t read(int fd, void *buf, size_t count)
char	*get_next_line(int fd)
{
	char	*theline;
	char	*joinstr;
	static char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	joinstr = NULL;
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (!gnl_find_nl(buf))
			joinstr = gnl_strjoin(joinstr, buf);
		if (gnl_find_nl(buf))
		{
			joinstr = gnl_strjoin(joinstr, buf);
			theline = gnl_substr(joinstr, 0));
			return (theline);
		}
		if (bytes_read == 0)
			break;
	}
	return (NULL);
}

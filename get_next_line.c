/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/22 19:19:50 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//ssize_t read(int fd, void *buf, size_t count)
char	*get_next_line(int fd)
{
	int	newline;
	static char	buf[3];
	ssize_t	bytes_read;

	newline = FALSE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	gnl_strjoin(,buf)
	printf("%zd\n", bytes_read); //DELETE ME
	if (bytes_read <= 0)
		return (NULL);
	return (buf);
}

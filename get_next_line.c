/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:29 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/25 11:09:43 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//ssize_t read(int fd, void *buf, size_t count)
char	*get_next_line(int fd)
{
	char	*joinstr;
	char	*theline;
	ssize_t	bytes_read;
	static char	buf[BUFFER_SIZE + 1];

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
			longjoinstr = gnl_strjoin(longjoinstr, buf);
			printf("1:%s\n", joinstr); //DELETE ME
			fflush(stdout);//DELETE ME
		if (gnl_find_nl(buf))
		{
			joinstr = gnl_strjoin(joinstr, buf);
			printf("2:%s\n", joinstr); //DELETE ME
			theline = gnl_substr(joinstr, 0, gnl_find_nl(buf));
			return (theline);
		}
		if (bytes_read == 0)
			break;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/23 16:19:41 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*gnl_find_nl(char	*buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (buf);
		buf++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *joinstr, char	*buf)
{
	int		i;

	i = 0;
	while (buf[i])
		i++;
	joinstr = malloc((i + 1) * sizeof(char));
	i = 0;
	while (buf[i])
	{
		joinstr[i] = buf[i];
		i++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}

char	*gnl_substr(char *src, int start, char delimeter)
{
	
}
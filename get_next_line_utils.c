/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/27 19:38:04 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char *gnl_free(char	*s1)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (s1);
}

int gnl_find_nl(char	*buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *pre_line, char *buf, int nl)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	while (pre_line[i])
		i++;
	if (nl == -1)
	{
		nl = BUFFER_SIZE;
	}
	else
	{
		nl = nl + 1;
	}
	str = malloc((i + nl + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (pre_line[i])
	{
		str[i] = pre_line[i];
		i++;
	}
	while (j < nl)
	{
		str[i++] = buf[j++];
	}
	str[i] = '\0';
	gnl_free(pre_line);
	return (str);
}

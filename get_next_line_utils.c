/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/26 17:08:22 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

gnl_free(char	*s1, char	*s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (s1);
}

char	*gnl_find_nl(char	*buf)
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

char	*gnl_strjoin(char *joinline, char *buf, int nl)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	while (joinline[i])
		i++;
	if (nl == -1)
		nl = BUFFER_SIZE;
	else
		nl++
	str = malloc((nl + i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (joinline[i])
		str[i++] = joinline[i++];
	while (j < nl)
		str[i++] = buf[j++];
	str[i] = '\0';
	return (str);
}

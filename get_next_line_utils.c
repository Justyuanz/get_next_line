/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/30 00:32:12 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int gnl_find_nl(char	*buf, char c)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
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
	j = -1;
	while (pre_line[i])
		i++;
	if (nl == -1)
		nl = gnl_strlen(buf);
	else
		nl += 1;
	str = malloc((i + nl + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (j++ < i)
		str[j] = pre_line[j];
	j = 0;
	while (j < nl)
		str[i++] = buf[j++];
	str[i] = '\0';
	free(pre_line);
	pre_line = NULL;
	return (str);
}

int gnl_updatebuf(char *buf)
{
	int	i;
	t_gnl	gnl;

	i = 0;
	gnl.nl = gnl_find_nl(buf, '\n');
	if (gnl.nl != -1 && (buf[gnl.nl +1] || buf[gnl.nl]))
	{
		while (buf[i])
		{
			if (gnl.nl + i + 1 <= gnl_strlen(buf))
				buf[i] = buf[gnl.nl + i + 1];
			i++;
		}
		buf[i] = '\0';
	}
	return (gnl.nl);
}
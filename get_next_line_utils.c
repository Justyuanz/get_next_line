/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/27 21:44:44 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

void gnl_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
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
	j = 0;
	while (pre_line[i])
		i++;
	if (nl == -1)
	{
		nl = ft_strlen(buf);
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
	gnl_free(&pre_line);
	return (str);
}

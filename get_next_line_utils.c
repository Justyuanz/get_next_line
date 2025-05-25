/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/25 15:52:38 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int	gnl_find_nl(char	*buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *src, char *buf)
{
	char	*ptr;

	ptr = malloc ((sizeof(src) + BUFFER_SIZE + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	
}

char	*gnl_substr(char *src, int i, int nl)
{
	char	*theline;

	theline = malloc((nl + 1) * sizeof (char));
	if (theline == NULL)
		return (NULL);
	while (i < nl + 1)
	{
		theline[i] = src[i];
		i++;
	}
	theline[i] = '\0';
	return (theline);
}

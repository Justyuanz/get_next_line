/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:34 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/30 13:43:36 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000
#endif

typedef struct s_gnl
{
	int	nl;
 	char	*line;
 	ssize_t	bytes_read;
} t_gnl;

char	*get_next_line(int fd);
char	*gnl_strjoin(char *pre_line, char *buf, int nl);
char 	*gnl_error_eof(t_gnl *gnl, char *buf);
int 	gnl_find_nl(char	*buf, char c);
int 	gnl_updatebuf(char *buf);
int 	gnl_strlen(char *str);

#endif
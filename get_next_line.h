/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:34 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/30 01:16:33 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> //DELETE ME
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 500000
#endif

#define FALSE -1

typedef struct s_gnl
{
	int	nl;
 	char	*line;
 	ssize_t	bytes_read;
} t_gnl;

char	*get_next_line(int fd);
void 	gnl_free(char **ptr);
int 	gnl_find_nl(char	*buf, char c);
char	*gnl_strjoin(char *pre_line, char *buf, int nl);
char	*gnl_substr(char *src, int i, int nl);
int gnl_updatebuf(char *buf);
int gnl_strlen(char *str);
char *gnl_error_eof(t_gnl *gnl, char *buf);

#endif
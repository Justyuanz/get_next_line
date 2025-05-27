/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:34 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/27 19:51:44 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> //DELETE ME
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 50
#endif

#define FALSE 0
#define TRUE 1

char	*get_next_line(int fd);
int gnl_find_nl(char	*buf);
char	*gnl_strjoin(char *pre_line, char *buf, int nl);
char	*gnl_substr(char *src, int i, int nl);
char *gnl_free(char	*s1);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:34 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/28 17:18:39 by jinzhang         ###   ########.fr       */
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
void 	gnl_free(char **ptr);
int 	gnl_find_nl(char	*buf, char c);
char	*gnl_strjoin(char *pre_line, char *buf, int nl);
char	*gnl_substr(char *src, int i, int nl);
void gnl_updatebuf(char *buf,int nl);
int gnl_strlen(char *str);

#endif
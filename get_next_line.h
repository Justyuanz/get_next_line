/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:34 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/26 12:17:55 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> //DELETE ME
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

#define FALSE 0
#define TRUE 1

char	*get_next_line(int fd);
char	*gnl_find_nl(char	*buf);
char	*gnl_strjoin(char *joinline, char *buf);
char	*gnl_substr(char *src, int i, int nl);

#endif
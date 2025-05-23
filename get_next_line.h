/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:18:34 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/23 15:39:01 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

#define FALSE 0
#define TRUE 1

char	*get_next_line(int fd);
char	*gnl_find_nl(char	*buf);
char	*gnl_strjoin(char *joinstr, char	*buf);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:57:48 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/12 19:49:56 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*buffer;
	char			*remains;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
t_list	*lst_new(int fd);
char	*gnl_join(char **line, t_list **lst, int *find);
void	*gnl_free(t_list **lst, char **line);
int		gnl_strlen(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:57:48 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/07 20:46:02 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*buff;
	size_t			start;
	int				rd_return;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
t_list	*lst_new(int fd);
char	*gnl_join(char *newline, t_list *lst, int *find);
size_t	ft_strchr(char *str, char c);
void	*free_all(t_list lst, char *newline);

#endif

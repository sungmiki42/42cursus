/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:29:08 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/12 21:16:38 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	gnl_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && *(str + len) && *(str + len) != '\n')
		len++;
	return (len);
}

void	*gnl_free(t_list **lst, char **line)
{
	if (*lst)
	{
		if ((*lst)->buffer)
			free((*lst)->buffer);
		free(*lst);
		*lst = 0;	
	}
	if (line && *line)
	{
		free(*line);
		*line = 0;
	}
	return (0);
}

char	*gnl_join(char **line, t_list **lst, int *find)
{
	int		join_len;
	int		line_len;
	int		i;
	char	*remains;
	char	*result;

	remains = (*lst)->remains;
	line_len = gnl_strlen(*line);
	join_len = gnl_strlen(remains);
	*find = (*(remains + join_len) == '\n');
	result = (char *)malloc(sizeof(char) * (line_len + join_len + *find + 1));
	if (result == 0)
		return (gnl_free(lst, line));
	i = 0;
	while (i < line_len)
	{
		*(result + i) = *(*line + i);
		i++;
	}
	while (i < line_len + join_len + *find)
		*(result + i++) = *(remains++);
	*(result + i) = 0;
	(*lst)->remains = remains;
	if (*find == 0 && *((*lst)->remains) == 0)
		(*lst)->remains = (*lst)->buffer;
	free(*line);
	return (result);
}

t_list	*lst_new(int fd)
{
	t_list	*new;

	if (fd < 0)
		return (0);
	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == 0)
		return (0);
	new->fd = fd;
	new->buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (new->buffer == 0)
		return (gnl_free(&new, 0));
	*(new->buffer + BUFFER_SIZE) = 0;
	new->remains = new->buffer;
	new->next = 0;
	return (new);
}

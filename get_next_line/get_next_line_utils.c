/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:29:08 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/07 20:46:37 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*lst_new(int fd)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node->fd = fd;
	node->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (node->buff == 0)
		return (free_all(node, 0));
	node->start = 0;
	node->rd_return = read(node->fd, node->buff, BUFFER_SIZE);
	*(node->buff + rd_return) = 0;
	node->next = 0;
	return (node);
}

char	*gnl_join(char *newline, t_list *lst, int *find)
{
	char	*joined;
	size_t	newline_len;
	size_t	buff_len;
	size_t	i;
	
	newline_len = 0;
   	while (*(newline + newline_len))
		newline_len++;	
	buff_len = ft_strchr(lst->buff + lst->start, '\n');
	joined = (char *)malloc(sizeof(char) * (newline_len + buff_len + 1));
	if (joined == 0)
		return (0);
	i = 0;
	while (i < newline)
		*(joined + i) = *(newline + i);
	i = 0;
	while (i <= buff_len)
		*(joined + newline_len + i) = *(lst->buff + i);
	if (lst->start + buff_len == BUFFER_SIZE)
		*find = 1;
	return (joined);
}

size_t	ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
}

void	*free_all(t_list lst, char *newline)
{
	if (lst)
	{
		free(lst->buff);
		free(lst);
	}
	if (newline)
		free(newline);
	return (0);
}

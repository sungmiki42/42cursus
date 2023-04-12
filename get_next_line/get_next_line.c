/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:54:23 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/12 21:16:45 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*newline;
	int				find;
	int				read_size;

	if (lst == 0)
		lst = lst_new(fd);
	if (lst == 0)
		return (0);
	find = 0;
	newline = 0;
	read_size = BUFFER_SIZE;
	while (!find && 0 < read_size && lst)
	{
		if (lst->remains == lst->buffer)
		{
			read_size = read(fd, lst->buffer, BUFFER_SIZE);
			*(lst->buffer + read_size) = 0;
		}
		if (0 < read_size)
			newline = gnl_join(&newline, &lst, &find);
	}
	if (read_size < 0)
		return (gnl_free(&lst, &newline));
	if (read_size == 0)
		gnl_free(&lst, 0);
	return (newline);
}

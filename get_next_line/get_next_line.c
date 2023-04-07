/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:01:13 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/07 20:46:40 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*newline;
	int				find;
	
	if (lst == 0)
	{	
		lst = lst_new(fd);
		if (lst == 0)
			return (0);
	}
	find = 0;
	newline = 0;
	while (lst->rd_return == BUFFER_SIZE && !find)
	{
		newline = gnl_join(newline, lst, &find);
		lst->rd_return = read(fd, lst->buff, BUFFER_SIZE);
		if (newline == 0 || lst->re_return < 0)
			return (free_all(lst, newline));
		*(lst->buff + lst->rd_return) = 0;
	}
	if (!find)
		free_all(lst, 0);
	return (newline);
}

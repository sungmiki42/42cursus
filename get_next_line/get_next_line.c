/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:01:13 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/04 20:34:07 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*new_line;
	int				read_cnt;
	size_t			i;

	if (fd < 0)
		return (0);
	if (lst == 0)
		lst = list_new(fd);
	if (lst->buffer == 0)
		lst->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	read_cnt = BUFFER_SIZE;
	new_line = 0;
	i = lst->start_i;
	while (i < read_cnt)
	{
		if (i == 0)	
		{	
			read_cnt = read(fd, lst->buffer, BUFFER_SIZE);
			if (read_cnt < 0)
				return (free_all(lst, new_line));
		}
		if (i = BUFFER_SIZE - 1 || *(lst->buffer + i) == '\n')
			gnl_join(new_line, buffer + start_i, i + 1);
		i = ++i % BUFFER_SIZE;
	}
	if (i == read_cnt)
		free_all(lst, 0);
	return (new_line);
}

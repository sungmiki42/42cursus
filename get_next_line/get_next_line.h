/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:57:48 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/04 20:34:11 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE = 1024;
# endif

# include <stdlib.h>
# include <unistd.h>

struct s_list
{

	int		fd;
	char	*buffer;
	size_t	start_i;
	t_list	*next;
} t_list;

char	*get_next_line(int	fd);

#endif

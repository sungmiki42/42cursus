/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:30:04 by sungmiki          #+#    #+#             */
/*   Updated: 2023/04/07 17:02:04 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	int		fd;

	fd = open("file1.txt", O_RDONLY);
	printf("get_next_line: %s\n", get_next_line(fd));
	printf("get_next_line: %s\n", get_next_line(fd));
	printf("get_next_line: %s\n", get_next_line(fd));
	printf("get_next_line: %s\n", get_next_line(fd));
}

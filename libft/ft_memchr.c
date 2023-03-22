/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:19:43 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/18 19:42:23 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy;
	size_t			i;

	copy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(copy + i) == (unsigned char)c)
			return ((void *)(copy + i));
		i++;
	}
	return (0);
}

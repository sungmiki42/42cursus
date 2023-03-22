/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:26:16 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/17 21:26:43 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i)) && \
			i + 1 < n)
		i++;
	return ((*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i)) * \
			(n != 0));
}

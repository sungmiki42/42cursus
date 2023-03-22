/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:57:58 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/17 19:25:39 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 1;
	while (i <= len)
	{
		*((unsigned char *)dst + len - i) = *((unsigned char *)src + len - i);
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		ft_memrcpy(dst, src, len);
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}

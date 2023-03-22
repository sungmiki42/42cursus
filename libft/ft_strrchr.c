/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:04:20 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/17 20:31:58 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	size_t	i;

	i = 0 ;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (*(str + len - i) == (unsigned char)c)
			return ((char *)str + len - i);
		i++;
	}
	return (0);
}

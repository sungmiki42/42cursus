/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:17:43 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/20 18:29:49 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	result = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		*(result + i) = f(i, *(s + i));
		i++;
	}
	return (result);
}

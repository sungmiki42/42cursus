/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:06:37 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/20 11:55:59 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*trim;

	start = 0;
	while (ft_strchr(set, *(s1 + start)) && *(s1 + start))
		start++;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, *(s1 + end - 1)))
		end--;
	trim = ft_substr(s1, start, end - start);
	return (trim);
}

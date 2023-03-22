/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:27:59 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/20 17:42:49 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_split_wc(char const *s, char c)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c && (*(s + i + 1) == c || *(s + i + 1) == 0))
			wc++;
		i++;
	}
	return (wc);
}

char	*ft_split_substr(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	return (ft_substr(s, 0, len));
}

char	**ft_split_free(char **splits)
{
	size_t	i;

	i = 0;
	while (*(splits + i))
		free(*(splits + i++));
	free(splits);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	size_t	i;
	size_t	wc;

	splits = (char **)ft_calloc(sizeof(char *), (ft_split_wc(s, c) + 1));
	if (splits == 0)
		return (0);
	i = 0;
	wc = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i))
			i++;
		if (*(s + i))
			*(splits + wc) = ft_split_substr(s + i, c);
		if (*(s + i) && *(splits + wc++) == 0)
			return (ft_split_free(splits));
		while (*(s + i) != c && *(s + i))
			i++;
	}
	return (splits);
}

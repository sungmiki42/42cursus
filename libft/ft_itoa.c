/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:14 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/21 14:33:18 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digit_count(int n)
{
	size_t	count;

	count = 1;
	while (n && ++count)
		n /= 10;
	return (count);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*result;

	digits = (n < 0) + ft_digit_count(n / 10);
	result = (char *)ft_calloc(sizeof(char), digits + 1);
	if (result == 0)
		return (0);
	while (0 <= --digits)
	{
		*(result + digits) = (n % 10) * ((0 <= n) - (n < 0)) + '0';
		n = (n / 10 == 0) * n + (n / 10 != 0) * n / 10 ;
	}
	if (n < 0)
		*(result) = '-';
	return (result);
}

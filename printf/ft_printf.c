/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmiki <sungmiki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:17:07 by sungmiki          #+#    #+#             */
/*   Updated: 2023/03/30 16:21:41 by sungmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puts_or_c(char *str, char letter, char type)
{
	int	size;

	if (type == 's')
	{
		if (str == 0)
			return (write(1, "(null)", 6));
		size = 0;
		while (*str)
		{
			if (write(1, str, 1) == -1)
				return (-1);
			str++;
			size++;
		}
		return (size);
	}
	else if (type == 'c')
		return (write(1, &letter, 1));
	return (-1);
}

int	ft_putmemory(unsigned long long addr)
{
	int	result;
	int	size;

	size = 0;
	if (addr / 16)
		result = ft_putmemory(addr / 16);
	else
		result = write(1, "0x", 2);
	if (result == -1)
		return (result);
	size += result;
	result = write(1, &"0123456789abcdef"[addr % 16], 1);
	if (result == -1)
		return (result);
	size += result;
	return (size);
}

int	ft_putnbr_base(long long nb, char type, int base)
{
	int		result;
	int		size;
	char	*base_set;

	result = 0;
	if (type == 'X')
		base_set = "0123456789ABCDEF";
	else
		base_set = "0123456789abcdef";
	size = 0;
	if (nb / base)
		result = ft_putnbr_base(nb / base, type, base);
	else if (nb < 0)
		result = write(1, "-", 1);
	if (result == -1)
		return (result);
	size += result;
	result = write(1, &base_set[(nb % base) * ((0 <= nb) - (nb < 0))], 1);
	if (result == -1)
		return (result);
	size += result;
	return (size);
}

int	ft_type_operator(va_list ap, char type)
{
	if (type == 'c')
		return (ft_puts_or_c(0, (char)va_arg(ap, int), type));
	else if (type == 's')
		return (ft_puts_or_c((char *)va_arg(ap, unsigned long long), 0, type));
	else if (type == 'p')
		return (ft_putmemory(va_arg(ap, unsigned long long)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr_base(va_arg(ap, int), type, 10));
	else if (type == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), type, 10));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), type, 16));
	else
		return (write(1, &type, 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;
	int		total;

	va_start(ap, str);
	total = 0;
	while (*str)
	{
		if (*str == '%')
			result = ft_type_operator(ap, *(++str));
		else
			result = write(1, str, 1);
		if (result == -1)
			return (result);
		total += result;
		str++;
	}
	return (total);
}

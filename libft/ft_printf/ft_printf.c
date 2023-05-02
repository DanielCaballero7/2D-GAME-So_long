/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:25:21 by dcaballe          #+#    #+#             */
/*   Updated: 2022/08/30 20:06:00 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converter(char c, int len, va_list list)
{
	if (c == 'c')
		len = ft_putchar(va_arg(list, int), len);
	else if (c == 's')
		len = ft_putstring(va_arg(list, char *), len);
	else if (c == 'p')
	{
		len = ft_putstring("0x", len);
		len = ft_puthex("0123456789abcdef", va_arg(list, unsigned long), len);
	}
	else if (c == 'd')
		len = ft_putnum(va_arg(list, int), len);
	else if (c == 'i')
		len = ft_putnum(va_arg(list, int), len);
	else if (c == 'u')
		len = ft_putunsigned(va_arg(list, unsigned int), len);
	else if (c == 'x')
		len = ft_puthex("0123456789abcdef", va_arg(list, unsigned int), len);
	else if (c == 'X')
		len = ft_puthex("0123456789ABCDEF", va_arg(list, unsigned int), len);
	else if (c == '%')
		len = ft_putchar('%', len);
	return (len);
}

int	ft_printf(char const *fmt, ...)
{
	int		len;
	char	*c;
	va_list	list;

	va_start(list, fmt);
	c = (char *)fmt;
	len = 0;
	while (*c != '\0')
	{
		if (*c++ != '%')
			len = ft_putchar(*(--c), len);
		else
			len = ft_converter(*c, len, list);
		c++;
	}
	return (len);
}

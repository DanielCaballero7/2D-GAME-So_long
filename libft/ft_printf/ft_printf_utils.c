/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:04:28 by dcaballe          #+#    #+#             */
/*   Updated: 2022/08/30 20:04:57 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_putstring(char *c, int len)
{
	if (!c)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	while (*c != '\0')
	{
		len = ft_putchar(*c, len);
		c++;
	}
	return (len);
}

int	ft_putnum(long n, int len)
{
	char	buf[13];
	char	*p;

	buf[12] = '\0';
	p = &buf[11];
	if (n < 0)
	{
		len = ft_putchar('-', len);
		n *= -1;
	}
	else if (n == 0)
		*p-- = 0 + '0';
	while (n != 0)
	{
		*p-- = ((n % 10) + '0');
		n /= 10;
	}
	p++;
	len = ft_putstring(p, len);
	return (len);
}

int	ft_putunsigned(unsigned int n, int len)
{
	if (n <= 9)
		len = ft_putchar((n + '0'), len);
	else
	{
		len++;
		len = ft_putunsigned((n / 10), len);
		ft_putchar((n % 10 + '0'), len);
	}
	return (len);
}

int	ft_puthex(char *digs, unsigned long n, int len)
{
	if (n < 16)
		len = ft_putchar(digs[n], len);
	else
	{
		len = ft_puthex(digs, n / 16, len);
		len = ft_putchar(digs[n % 16], len);
	}
	return (len);
}

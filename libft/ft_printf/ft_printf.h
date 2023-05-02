/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:51:49 by dcaballe          #+#    #+#             */
/*   Updated: 2022/08/30 20:06:48 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *fmt, ...);
int	ft_putchar(char c, int len);
int	ft_putstring(char *c, int len);
int	ft_putdecimal(int n, int len);
int	ft_putnum(long n, int len);
int	ft_putunsigned(unsigned int n, int len);
int	ft_puthex(char *digs, unsigned long n, int len);
int	ft_converter(char c, int len, va_list list);

#endif

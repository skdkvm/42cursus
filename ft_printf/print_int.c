/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 23:25:08 by seonggki          #+#    #+#             */
/*   Updated: 2021/01/25 21:22:34 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		ft_putint(long n)
{
	char	c;
	int		len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = -n;
	}
	if (n / 10 > 0)
		len += ft_putint(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

int		ft_putint_prewidth(long n, t_flag flag)
{
	int len;
	int count;
	int padding;

	len = 0;
	count = flag.precision - ft_intlen(n);
	count += (n < 0) ? 1 : 0;
	count = (count > 0) ? count : 0;
	padding = flag.width - ft_intlen(n) - count;
	padding = (padding > 0) ? padding : 0;
	len += padding + count + ft_intlen(n);
	while (flag.neg == 0 && padding-- > 0)
		write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (count-- > 0)
		write(1, "0", 1);
	ft_putint(n);
	while (flag.neg == 1 && padding-- > 0)
		write(1, " ", 1);
	return (len);
}

int		ft_putint_pre(long n, t_flag flag)
{
	int len;
	int count;

	len = 0;
	count = (flag.dot == 1) ? flag.precision : flag.width;
	count -= (n < 0 && flag.dot == 1) ? ft_intlen(n) - 1 : ft_intlen(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	while (count-- > 0)
	{
		write(1, "0", 1);
		len++;
	}
	len += ft_putint(n);
	return (len);
}

int		ft_putint_width(long n, t_flag flag)
{
	int len;
	int padding;

	len = 0;
	padding = flag.width - ft_intlen(n);
	while (flag.neg == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	len += ft_putint(n);
	while (flag.neg == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

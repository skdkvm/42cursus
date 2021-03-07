/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:21:47 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/14 23:22:41 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write(int i)
{
	char c;

	if (i < 10)
	{
		i += '0';
		write(1, &i, 1);
	}
	else
	{
		c = i % 10 + '0';
		i /= 10;
		ft_write(i);
		write(1, &c, 1);
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0)
		ft_write(n);
	else
	{
		n *= -1;
		write(1, "-", 1);
		ft_write(n);
	}
}

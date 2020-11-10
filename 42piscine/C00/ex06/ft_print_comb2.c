/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:41:17 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/05 11:30:49 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ex(int nb)
{
	int	a;
	int	b;

	if (nb > 9)
	{
		a = nb / 10;
		b = nb % 10;
		ft_putchar(a + 48);
		ft_putchar(b + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(nb + 48);
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int y;

	x = 0;
	while (x <= 99)
	{
		y = x + 1;
		while (y <= 99)
		{
			ex(x);
			ft_putchar(' ');
			ex(y);
			if (x < 98 || y < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			++y;
		}
		++x;
	}
}

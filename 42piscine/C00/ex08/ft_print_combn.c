/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:38:35 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/05 11:31:06 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int n, int num[])
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(num[i] + 48);
		i++;
	}
	if (!(num[0] == 10 - n && num[n - 1] == 9))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	comb(int a, int b, int num2[])
{
	int i;

	if (a == b)
	{
		print(a, num2);
	}
	else
	{
		if (b == 0)
			i = 0;
		else
			i = num2[b - 1] + 1;
		while (i <= 9)
		{
			num2[b] = i;
			comb(a, b + 1, num2);
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int num2[10];

	comb(n, 0, num2);
}

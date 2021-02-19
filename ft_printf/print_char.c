/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:37:07 by seonggki          #+#    #+#             */
/*   Updated: 2021/01/25 21:22:23 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putchar_minwidth(char c, int width)
{
	int count;

	count = 0;
	write(1, &c, 1);
	while (count++ < width - 1)
		write(1, " ", 1);
	return (width);
}

int		ft_putchar_zerowidth(char c, int width)
{
	int count;

	count = 0;
	while (count++ < width - 1)
		write(1, "0", 1);
	write(1, &c, 1);
	return (width);
}

int		ft_putchar_width(char c, int width)
{
	int count;

	count = 0;
	while (count++ < width - 1)
		write(1, " ", 1);
	write(1, &c, 1);
	return (width);
}

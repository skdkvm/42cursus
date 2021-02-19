/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:37:40 by seonggki          #+#    #+#             */
/*   Updated: 2021/01/25 21:40:56 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_none(char c, t_flag flag)
{
	int padding;

	padding = flag.width - 1;
	if (c == '\0')
		return (0);
	while (flag.neg == 0 && flag.zero == 0 && padding-- > 0)
		write(1, " ", 1);
	while (flag.neg == 0 && flag.zero == 1 && padding-- > 0)
		write(1, "0", 1);
	write(1, &c, 1);
	while (flag.neg == 1 && padding-- > 0)
		write(1, " ", 1);
	if (flag.width > 0)
		return (flag.width);
	else
		return (1);
}

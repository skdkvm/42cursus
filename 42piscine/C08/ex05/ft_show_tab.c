/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <tjdrlf0618@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:18:06 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/18 16:43:02 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_print_num(int nb)
{
	char	num;

	if (nb >= 10)
	{
		ft_print_num(nb / 10);
		ft_print_num(nb % 10);
	}
	else
	{
		num = nb + '0';
		write(1, &num, 1);
	}
}

void	ft_print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_print_str(par[i].str);
		ft_print_num(par[i].size);
		write(1, "\n", 1);
		ft_print_str(par[i].copy);
		i++;
	}
}

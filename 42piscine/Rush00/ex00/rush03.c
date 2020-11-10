/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:39:28 by yjang             #+#    #+#             */
/*   Updated: 2020/08/02 22:11:09 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char c);

void			make_line(int x, char fir, char mid, char fin)
{
	int tmp_x;

	tmp_x = x;
	while (x)
	{
		if (x == tmp_x)
			ft_putchar(fir);
		else if (x == 1)
			ft_putchar(fin);
		else
			ft_putchar(mid);
		x--;
	}
	ft_putchar('\n');
}

void			rush(int x, int y)
{
	int tmp_y;

	tmp_y = y;
	while (y)
	{
		if (y == tmp_y)
			make_line(x, 'A', 'B', 'C');
		else if (y == 1)
			make_line(x, 'A', 'B', 'C');
		else
			make_line(x, 'B', ' ', 'B');
		y--;
	}
}

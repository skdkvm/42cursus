/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <tjdrlf0618@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 03:13:38 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/20 03:21:10 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char	a;
	char	b;

	a = 'a';
	b = 'B';
	while (a <= 'z' && b <= 'Z')
	{
		ft_putchar(a);
		ft_putchar(b);
		a += 2;
		b += 2;
	}
	ft_putchar('\n');
	return (0);
}

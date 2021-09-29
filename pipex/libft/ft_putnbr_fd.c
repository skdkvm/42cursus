/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:58:57 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 14:58:58 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		mod;

	mod = n % 10;
	n /= 10;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	if (mod < 0)
	{
		if (n == 0)
			write(fd, "-", 1);
		mod = -mod + '0';
		write(fd, &mod, 1);
	}
	else
	{
		mod += '0';
		write(fd, &mod, 1);
	}
}

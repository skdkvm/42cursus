/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:00:14 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 15:00:15 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ulen(unsigned int n)
{
	int		len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static void	ft_chrcat(char *str, char c)
{
	str = ft_strchr(str, 0);
	*str++ = c;
	*str = 0;
}

static void	ft_putnbr_str(unsigned int n, char *str)
{
	int		tmp;

	tmp = n % 10;
	n /= 10;
	if (n != 0)
		ft_putnbr_str(n, str);
	ft_chrcat(str, tmp + '0');
}

char		*ft_utoa(unsigned int n)
{
	char	*res;

	if (!(res = (char *)malloc(ft_ulen(n) + 1)))
		return (0);
	*res = 0;
	ft_putnbr_str(n, res);
	return (res);
}

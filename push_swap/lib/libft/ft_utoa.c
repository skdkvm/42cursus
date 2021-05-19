/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:22:43 by seushin           #+#    #+#             */
/*   Updated: 2021/01/06 18:30:29 by seushin          ###   ########.fr       */
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

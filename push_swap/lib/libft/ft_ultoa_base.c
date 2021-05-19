/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:39:47 by seushin           #+#    #+#             */
/*   Updated: 2021/01/11 16:40:09 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nlen_base(unsigned long n, int base)
{
	int		len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

void		ft_pushback_char(char *str, char c)
{
	char	*tmp;

	if (!(tmp = ft_strchr(str, '\0')))
		tmp = str;
	*tmp++ = c;
	*tmp = '\0';
}

void		ft_putnbr_str_base(unsigned long n, char *str, char *base, int ib)
{
	int		mod;

	mod = n % ib;
	n /= ib;
	if (n != 0)
		ft_putnbr_str_base(n, str, base, ib);
	if (mod < 0)
	{
		if (n == 0)
			ft_pushback_char(str, '-');
		ft_pushback_char(str, base[-mod]);
	}
	else
		ft_pushback_char(str, base[mod]);
}

char		*ft_ultoa_base(unsigned long n, char *base)
{
	char	*res;
	int		len;
	int		ibase;

	ibase = ft_strlen(base);
	len = ft_nlen_base(n, ibase);
	if (!(res = (char *)malloc(len + 1)))
		return (0);
	*res = '\0';
	ft_putnbr_str_base(n, res, base, ibase);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:15:13 by seonggki          #+#    #+#             */
/*   Updated: 2020/10/22 15:08:48 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_len(long long n)
{
	size_t		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*res;
	size_t		len;

	len = ft_len(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		--len;
		res[len] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (res);
}

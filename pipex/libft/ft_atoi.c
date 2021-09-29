/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:56:39 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 14:56:42 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		neg;
	int		len;

	res = 0;
	neg = 1;
	len = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = -1;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += neg * (*str++ - '0');
		len++;
	}
	if (len > 18)
		return (neg == 1 ? -1 : 0);
	return (res);
}

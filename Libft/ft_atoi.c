/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:25:41 by seonggki          #+#    #+#             */
/*   Updated: 2020/10/14 15:36:23 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		whitespace(int c)
{
	if (c == '\n' || c == '\v' || c == '\t' || c == '\f'
	|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str[i])
		return (0);
	while (whitespace(str[i]))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}

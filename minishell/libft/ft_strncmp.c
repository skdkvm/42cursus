/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:36 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:32:37 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	i = 0;
	if (num == 0)
	{
		while ((p1[i] || p2[i]) && p1[i] == p2[i])
			i++;
	}
	else
	{
		while ((p1[i] || p2[i]) && i < num - 1 && p1[i] == p2[i])
			i++;
	}
	return (p1[i] - p2[i]);
}

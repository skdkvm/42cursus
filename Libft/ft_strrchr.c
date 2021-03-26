/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:13:47 by seonggki          #+#    #+#             */
/*   Updated: 2020/10/07 14:26:05 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s2;
	char	c2;

	s2 = (char *)s;
	c2 = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i--;
	}
	if (s2[i] == c2)
		return (s2);
	return (0);
}

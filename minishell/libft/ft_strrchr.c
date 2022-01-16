/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:45 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:32:47 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ps;

	ps = (char *)s;
	i = ft_strlen(ps);
	while (i >= 0 && ps[i] != c)
		i--;
	if (i == -1)
		return (NULL);
	return (&ps[i]);
}

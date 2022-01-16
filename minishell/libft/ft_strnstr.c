/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:39 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:32:40 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[i] == '\0')
		return ((char *)s);
	if (slen > ft_strlen(s))
		slen = ft_strlen(s);
	while (i < slen && s[i])
	{
		j = 0;
		while (find[j] && s[i + j] && s[i + j] == find[j] && (i + j) < slen)
			j++;
		if (find[j] == '\0')
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

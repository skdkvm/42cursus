/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:59:15 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 14:59:16 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*res;
	size_t	size;

	size = ft_strlen(s) + 1;
	if (!(res = (char *)malloc(size)))
		return (0);
	ft_strlcpy(res, s, size);
	return (res);
}

char		*ft_strndup(const char *s, int n)
{
	char	*res;
	int		i;

	if (!s)
		return (0);
	if (!(res = (char *)malloc(n + 1)))
		return (0);
	i = 0;
	while (n--)
		res[i++] = *s++;
	res[i] = 0;
	return (res);
}

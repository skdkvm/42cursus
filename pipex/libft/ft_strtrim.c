/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:59:58 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 14:59:59 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_find(const char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start] && to_find(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && to_find(s1[end], set))
		end--;
	if (!(res = (char *)malloc(end - start + 2)))
		return (0);
	ft_strlcpy(res, s1 + start, end - start + 2);
	return (res);
}

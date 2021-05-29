/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:59:49 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 14:59:49 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		ndl_len;

	ndl_len = ft_strlen(needle);
	if (!ndl_len)
		return ((char *)haystack);
	while (*haystack && len >= ndl_len)
	{
		if (ft_strncmp(haystack, needle, ndl_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}

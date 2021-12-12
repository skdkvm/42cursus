/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 04:22:53 by seonggki          #+#    #+#             */
/*   Updated: 2020/10/12 18:54:03 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (dst == 0 || src == 0)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	if (!src)
		return (0);
	if (dst == 0 || size == 0)
		return (src_len);
	while (i < src_len && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

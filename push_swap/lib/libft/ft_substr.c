/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:00:01 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 15:00:02 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	str_len;

	if (!s)
		return (0);
	while (*s && start--)
		s++;
	str_len = ft_strlen(s);
	str_len = str_len > len ? len : str_len;
	if (!(res = (char *)malloc(str_len + 1)))
		return (0);
	ft_strlcpy(res, s, str_len + 1);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <tjdrlf0618@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:13:01 by seonggki          #+#    #+#             */
/*   Updated: 2020/10/12 20:34:36 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1 == 0 || s2 == 0)
		return (0);
	res = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s1, s1_len + 1);
	ft_strlcat(res + (s1_len), s2, s2_len + 1);
	return (res);
}

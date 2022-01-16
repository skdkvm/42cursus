/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:55 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:32:56 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (!(*set) && set == NULL)
		return ((char *)s1);
	while (*s1 && ft_strchr(set, (int)*s1))
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && ft_strrchr(set, s1[size - 1]))
		size--;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (str)
		ft_strlcpy(str, s1, size + 1);
	return (str);
}

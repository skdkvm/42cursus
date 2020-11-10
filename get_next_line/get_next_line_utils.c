/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:23:27 by seonggki          #+#    #+#             */
/*   Updated: 2020/11/10 21:47:47 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char			*ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

char			*ft_strdup(const char *src)
{
	char	*result;
	int		i;

	i = 0;
	while (src[i])
		i++;
	result = (char *)malloc(sizeof(char) * i + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*s3;
	int			i;

	if (!(s3 = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		s3[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		s3[i] = *s2++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

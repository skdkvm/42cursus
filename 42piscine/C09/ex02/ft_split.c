/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 03:34:17 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/19 03:59:34 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void			ft_strcpy(char *dest, char *src, char *strs)
{
	while (src < strs)
		*(dest++) = *(src++);
	*dest = 0;
}

int				ft_word_count(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (!ft_charset(*str, charset))
		{
			++count;
			while (*str && !ft_charset(*str, charset))
				++str;
		}
		++str;
	}
	return (count);
}

char			**ft_split(char *str, char *charset)
{
	char		**arr;
	char		*dest;
	long long	i;

	arr = (char**)malloc(sizeof(char*) * ft_word_count(str, charset) + 1);
	if (!arr)
		return (0);
	i = 0;
	while (*str)
	{
		if (!ft_charset(*str, charset))
		{
			dest = str;
			while (*str && !ft_charset(*str, charset))
				++str;
			arr[i] = (char*)malloc(str - dest + 1);
			ft_strcpy(arr[i++], dest, str);
		}
		++str;
	}
	arr[i] = 0;
	return (arr);
}

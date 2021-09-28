/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:57:13 by seonggki          #+#    #+#             */
/*   Updated: 2020/10/14 15:24:08 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_word_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && str[i] != 0)
		{
			count++;
			while (str[i] != c && str[i] != 0)
				i++;
		}
		else if (str[i] != 0)
			i++;
	}
	return (count);
}

static	void		ft_strcpy(char *dest, char const *src, int start, int end)
{
	int		i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = 0;
}

static	void		split(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			str[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			ft_strcpy(str[j], s, start, i);
			j++;
		}
		else if (s[i] != 0)
			i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char	**str;
	size_t	wc;

	if (s == 0)
		return (0);
	wc = ft_word_count((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (wc + 1));
	if (str == 0)
		return (0);
	str[wc] = 0;
	if (wc == 0)
		return (str);
	split(s, c, str);
	return (str);
}

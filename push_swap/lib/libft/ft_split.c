/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:40:18 by seushin           #+#    #+#             */
/*   Updated: 2021/04/24 14:32:14 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_words(const char *s, char c)
{
	int		count;

	count = 0;
	while (s && *s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			s = ft_strchr(s, c);
		}
	}
	return (count);
}

static void	free_all(char **strs, int i)
{
	while (i--)
		free(strs[i]);
	free(strs);
}

char		**ft_split(const char *s, char c)
{
	char	**res;
	int		count;
	int		len;
	int		i;

	if (!s)
		return (0);
	count = count_words(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = -1;
	while (++i < count)
	{
		while (*s && *s == c)
			s++;
		len = ft_strchr(s, c) ? ft_strchr(s, c) - s : ft_strlen(s);
		if (!(res[i] = ft_substr(s, 0, len)))
		{
			free_all(res, i);
			return (0);
		}
		s = ft_strchr(s, c);
	}
	res[i] = 0;
	return (res);
}

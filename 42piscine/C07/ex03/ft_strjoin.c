/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:25:09 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/18 21:28:30 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	return (dest);
}

char	*size_null(void)
{
	char	*null;

	null = ((char*)malloc(sizeof(char)));
	*null = '\0';
	return (null);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	char	*ptr;
	int		len;
	int		i;

	if (size == 0)
		return (size_null());
	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	arr = (char*)malloc(len + (size - 1) * ft_strlen(sep) + 1);
	if (!arr)
		return (0);
	ptr = ft_strcat(arr, strs[0]);
	i = 1;
	while (i < size)
	{
		ptr = ft_strcat(ptr, sep);
		ptr = ft_strcat(ptr, strs[i++]);
	}
	*ptr = 0;
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <tjdrlf0618@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:28:18 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/18 16:16:47 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
}

void				ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct	s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	t_stock_str *arr;
	int			i;

	arr = (t_stock_str*)malloc(sizeof(t_stock_str) * (argc + 1));
	if (arr == 0)
	{
		return (0);
	}
	i = 0;
	while (i < argc)
	{
		arr[i].size = ft_strlen(argv[i]);
		arr[i].str = (char*)malloc(arr[i].size + 1);
		arr[i].copy = (char*)malloc(arr[i].size + 1);
		ft_strcpy(arr[i].str, argv[i]);
		ft_strcpy(arr[i].copy, argv[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

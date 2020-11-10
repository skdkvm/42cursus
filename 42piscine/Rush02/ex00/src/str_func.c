/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:29:34 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/16 00:31:11 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../myheader.h"

int		ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*(str + length))
		length++;
	return (length);
}

int		ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1 - str2);
		i++;
	}
	return (0);
}

void	ft_strcat(char *g_result, char *src)
{
	int i;
	int rlen;

	i = 0;
	rlen = 0;
	while (g_result[rlen] != '\0')
		rlen++;
	while (src[i] != '\0')
	{
		g_result[rlen] = src[i];
		g_result++;
		i++;
	}
	g_result[rlen] = ' ';
	g_result[rlen + 1] = src[i];
}

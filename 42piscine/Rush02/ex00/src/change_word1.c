/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_word1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:29:01 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/16 00:30:03 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../myheader.h"

int	change_to_word(void)
{
	int		index;

	index = -1;
	g_result = (char *)malloc(sizeof(char) * BUF_SIZE);
	while (g_num[++index])
	{
		if (zero_row(index))
			continue;
		if (change_for_num(index))
			return (print_dict_err());
		if (change_for_unit(index))
			return (print_dict_err());
	}
	if (g_result[0] == '\0')
		match_word("0");
	print_word();
	return (0);
}

int	change_for_num(int index)
{
	char	temp[2];

	temp[0] = '\0';
	temp[1] = '\0';
	if (g_num[index][0] > '0')
	{
		temp[0] = g_num[index][0];
		temp[1] = '\0';
		if (match_word(temp) == 0)
			return (1);
		if (match_word("100") == 0)
			return (1);
	}
	return (change_for_ten(index));
}

int	change_for_ten(int index)
{
	char	temp[3];

	temp[0] = g_num[index][1];
	temp[2] = '\0';
	if (temp[0] == '1')
	{
		temp[1] = g_num[index][2];
		if (match_word(temp) == 0)
			return (1);
		return (0);
	}
	if (temp[0] > '1')
	{
		temp[1] = '0';
		if (match_word(temp) == 0)
			return (1);
	}
	if (g_num[index][2] > '0')
	{
		temp[0] = g_num[index][2];
		temp[1] = '\0';
		if (match_word(temp) == 0)
			return (1);
	}
	return (0);
}

int	change_for_unit(int index)
{
	int		unit_num;
	char	*cmp_str;
	int		i;

	if (index == g_max_num)
		return (0);
	i = 1;
	unit_num = (g_max_num - index) * 3 + 1;
	cmp_str = (char *)malloc(sizeof(char) * (unit_num + 1));
	cmp_str[0] = '1';
	while (i < unit_num)
	{
		cmp_str[i] = '0';
		i++;
	}
	cmp_str[i] = '\0';
	if (match_word(cmp_str) == 0)
		return (1);
	free(cmp_str);
	return (0);
}

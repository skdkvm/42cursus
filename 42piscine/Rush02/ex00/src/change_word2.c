/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_word2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:28:53 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/16 00:31:33 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../myheader.h"

void	print_word(void)
{
	g_result[ft_strlen(g_result)] = '\n';
	write(1, g_result, ft_strlen(g_result));
	free(g_result);
}

int		zero_row(int index)
{
	if (g_num[index][0] == '0' && g_num[index][1] == '0')
	{
		if (g_num[index][2] == '0')
		{
			return (1);
		}
	}
	return (0);
}

int		match_word(char *cmp_str)
{
	int i;

	i = 0;
	while (i < g_max_dict)
	{
		if (ft_strcmp(g_dict[i].key, cmp_str) == 0)
		{
			ft_strcat(g_result, g_dict[i].value);
			return (1);
		}
		i++;
	}
	return (0);
}

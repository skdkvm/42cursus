/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:29:28 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/16 00:34:09 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../myheader.h"

int			ft_malloc(int argc, char *argv[])
{
	int		row;
	int		size;

	row = 0;
	size = ft_strlen(argv[argc - 1]);
	g_num = (char**)malloc(sizeof(char*) * (size / 3 + 2));
	if (g_num == NULL)
		return (0);
	if (size % 3 == 0)
		size /= 3;
	else
		size = size / 3 + 1;
	while (row < size)
	{
		g_num[row] = (char *)malloc(4);
		if (g_num[row] == NULL)
			return (0);
		row++;
	}
	return (1);
}

void		init_input(int argc, char *argv[], int col)
{
	int		i;
	int		row;

	i = 0;
	row = 0;
	while (argv[argc - 1][i] != '\0')
	{
		g_num[row][col] = argv[argc - 1][i];
		if (col == 2)
		{
			g_num[row][3] = '\0';
			row++;
			col = -1;
		}
		col++;
		i++;
	}
	g_max_num = row - 1;
	g_num[row] = 0;
}

int			split_num(int argc, char *argv[])
{
	int		col;

	if (ft_malloc(argc, argv) == 0)
		return (1);
	if (ft_strlen(argv[argc - 1]) % 3 == 1)
	{
		g_num[0][0] = '0';
		g_num[0][1] = '0';
		col = 2;
	}
	if (ft_strlen(argv[argc - 1]) % 3 == 2)
	{
		g_num[0][0] = '0';
		col = 1;
	}
	if (ft_strlen(argv[argc - 1]) % 3 == 0)
		col = 0;
	init_input(argc, argv, col);
	return (0);
}

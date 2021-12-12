/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:06:15 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:21:39 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_wall(t_info *info, char *str)
{
	while (*str)
	{
		if (*str != '1')
		{
			ft_putstr_fd("Error\nThe map isn't closed\n", 2);
			free_info(info);
			exit(EXIT_FAILURE);
		}
		str++;
	}
}

void	check_collect_exit(t_info *info, char *str, int line_index)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'P')
		{
			info->player_pos[0] = i;
			info->player_pos[1] = line_index;
			info->player++;
		}
		if (str[i] == 'C')
			info->collect++;
		if (str[i] == 'E')
			info->exit++;
	}
}

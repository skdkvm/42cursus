/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:44:44 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/24 21:30:26 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	check_map_user(t_main *m)
{
	if (m->map.user == 0)
	{
		free_array(m->map.map);
		error_write(10);
	}
}

void	check_map_wall(t_main *m, int i, int j)
{
	if (i == 0 || j == 0 || i == m->map.x - 1 || j == m->map.y - 1)
	{
		if (!(m->map.map[i][j] == '1' || (i == 0 && m->map.map[i][j] == 'n') ||
			(j == 0 && m->map.map[i][j] == 'n') || (i == m->map.x - 1 &&
			m->map.map[i][j] == 'n') ||
				(j == m->map.y - 1 && m->map.map[i][j] == 'n')))
		{
			free_array(m->map.map);
			error_write(7);
		}
	}
	else
	{
		if ((m->map.map[i][j] == '0' || m->map.map[i][j] == '2' ||
			m->map.map[i][j] == 'N' || m->map.map[i][j] == 'E' ||
				m->map.map[i][j] == 'S' || m->map.map[i][j] == 'W') &&
					(m->map.map[i - 1][j] == 'n' ||
					m->map.map[i + 1][j] == 'n' || m->map.map[i][j + 1] == 'n'))
		{
			free_array(m->map.map);
			error_write(7);
		}
	}
}

void	check_map(t_main *m)
{
	int	i;
	int	j;

	if (m->map.x < 3 || m->map.y < 3)
	{
		free_array(m->map.map);
		error_write(8);
	}
	i = -1;
	while (++i < m->map.x)
	{
		j = -1;
		while (++j < m->map.y)
		{
			check_map_wall(m, i, j);
			find_pos(m, m->map.map[i][j], i, j);
			if (m->map.map[i][j] == '2')
				++m->map.spr;
		}
	}
	check_map_user(m);
	put_sprite(m);
}

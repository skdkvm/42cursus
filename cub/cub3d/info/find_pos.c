/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:37:29 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/31 16:32:31 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_pos_two(t_main *m, char c)
{
	if (c == 'S')
	{
		m->dir.x = 1;
		m->plane.x = 0;
		m->plane.y = -PLANE;
	}
	if (c == 'E')
	{
		m->dir.x = 0;
		m->dir.y = 1;
		m->plane.x = PLANE;
		m->plane.y = 0;
	}
	if (c == 'W')
	{
		m->dir.x = 0;
		m->dir.y = -1;
		m->plane.x = -PLANE;
		m->plane.y = 0;
	}
}

void	find_pos(t_main *m, char c, int i, int j)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && m->map.user == 0)
	{
		m->pos.x = (double)i + 0.5;
		m->pos.y = (double)j + 0.5;
		m->map.user = 1;
	}
	else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && m->map.user != 0)
	{
		free_array(m->map.map);
		error_write(9);
	}
	if (c == 'N')
	{
		m->dir.x = -1;
		m->dir.y = 0;
		m->plane.x = 0;
		m->plane.y = PLANE;
	}
	find_pos_two(m, c);
}

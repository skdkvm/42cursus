/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:16:10 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/26 14:16:10 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting_set(t_main *m)
{
	m->v.camera_x = 2 * m->v.i / (double)m->w - 1;
	m->v.ray_x = m->dir.x + m->plane.x * m->v.camera_x;
	m->v.ray_y = m->dir.y + m->plane.y * m->v.camera_x;
	m->v.map_x = (int)m->pos.x;
	m->v.map_y = (int)m->pos.y;
	m->v.delta_x = fabs(1 / m->v.ray_x);
	m->v.delta_y = fabs(1 / m->v.ray_y);
	m->v.hit = 0;
}

void	raycasting_side_xy(t_main *m)
{
	if (m->v.ray_x < 0)
	{
		m->v.step_x = -1;
		m->v.side_x = (m->pos.x - m->v.map_x) * m->v.delta_x;
	}
	else
	{
		m->v.step_x = 1;
		m->v.side_x = (m->v.map_x + 1.0 - m->pos.x) * m->v.delta_x;
	}
	if (m->v.ray_y < 0)
	{
		m->v.step_y = -1;
		m->v.side_y = (m->pos.y - m->v.map_y) * m->v.delta_y;
	}
	else
	{
		m->v.step_y = 1;
		m->v.side_y = (m->v.map_y + 1.0 - m->pos.y) * m->v.delta_y;
	}
}

void	raycasting_map_xy(t_main *m)
{
	while (m->v.hit == 0)
	{
		if (m->v.side_x < m->v.side_y)
		{
			m->v.side_x += m->v.delta_x;
			m->v.map_x += m->v.step_x;
			m->v.side = 0;
		}
		else
		{
			m->v.side_y += m->v.delta_y;
			m->v.map_y += m->v.step_y;
			m->v.side = 1;
		}
		if (m->map.map[m->v.map_x][m->v.map_y] == '1')
			m->v.hit = 1;
	}
	if (m->v.side == 0)
		m->v.wall_dist =
			(m->v.map_x - m->pos.x + (1 - m->v.step_x) / 2) / m->v.ray_x;
	else
		m->v.wall_dist =
			(m->v.map_y - m->pos.y + (1 - m->v.step_y) / 2) / m->v.ray_y;
}

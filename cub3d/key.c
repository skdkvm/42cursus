/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:09:52 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/26 15:16:56 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_up_down(int keycode, t_main *m)
{
	if (keycode == KEY_ESC)
	{
		free_array(m->map.map);
		free(m->sp);
		exit(0);
	}
	if (keycode == KEY_W)
	{
		if (m->map.map[(int)(m->pos.x + m->dir.x * SPEED)]
					[(int)m->pos.y] != '1')
			m->pos.x += m->dir.x * SPEED;
		if (m->map.map[(int)m->pos.x]
					[(int)(m->pos.y + m->dir.y * SPEED)] != '1')
			m->pos.y += m->dir.y * SPEED;
	}
	if (keycode == KEY_S)
	{
		if (m->map.map[(int)(m->pos.x - m->dir.x * SPEED)]
					[(int)m->pos.y] != '1')
			m->pos.x -= m->dir.x * SPEED;
		if (m->map.map[(int)m->pos.x]
					[(int)(m->pos.y - m->dir.y * SPEED)] != '1')
			m->pos.y -= m->dir.y * SPEED;
	}
}

void	key_left_right(int keycode, t_main *m)
{
	if (keycode == KEY_A)
	{
		if (m->map.map[(int)(m->pos.x - m->dir.y * SPEED)]
					[(int)m->pos.y] != '1')
			m->pos.x -= m->dir.y * SPEED;
		if (m->map.map[(int)m->pos.x]
					[(int)(m->pos.y + m->dir.x * SPEED)] != '1')
			m->pos.y += m->dir.x * SPEED;
	}
	if (keycode == KEY_D)
	{
		if (m->map.map[(int)(m->pos.x + m->dir.y * SPEED)]
					[(int)m->pos.y] != '1')
			m->pos.x += m->dir.y * SPEED;
		if (m->map.map[(int)m->pos.x]
					[(int)(m->pos.y - m->dir.x * SPEED)] != '1')
			m->pos.y -= m->dir.x * SPEED;
	}
}

void	key_rotate(int keycode, t_main *m)
{
	double tem_dir_x;
	double tem_plane_x;

	if (keycode == KEY_RIGHT)
	{
		tem_dir_x = m->dir.x;
		m->dir.x = m->dir.x * cos(-ROTATE) - m->dir.y * sin(-ROTATE);
		m->dir.y = tem_dir_x * sin(-ROTATE) + m->dir.y * cos(-ROTATE);
		tem_plane_x = m->plane.x;
		m->plane.x = m->plane.x * cos(-ROTATE) - m->plane.y * sin(-ROTATE);
		m->plane.y = tem_plane_x * sin(-ROTATE) + m->plane.y * cos(-ROTATE);
	}
	if (keycode == KEY_LEFT)
	{
		tem_dir_x = m->dir.x;
		m->dir.x = m->dir.x * cos(ROTATE) - m->dir.y * sin(ROTATE);
		m->dir.y = tem_dir_x * sin(ROTATE) + m->dir.y * cos(ROTATE);
		tem_plane_x = m->plane.x;
		m->plane.x = m->plane.x * cos(ROTATE) - m->plane.y * sin(ROTATE);
		m->plane.y = tem_plane_x * sin(ROTATE) + m->plane.y * cos(ROTATE);
	}
}

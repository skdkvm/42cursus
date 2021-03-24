/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:31:32 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/24 22:10:20 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		raycasting_texture_1(t_main *m)
{
	m->v.line_h = (int)(m->h / m->v.wall_dist);
	m->v.draw_start = -m->v.line_h / 2 + m->h / 2;
	if (m->v.draw_start < 0)
		m->v.draw_start = 0;
	m->v.draw_end = m->v.line_h / 2 + m->h / 2;
	if (m->v.draw_end >= m->h)
		m->v.draw_end = m->h - 1;
	if (m->v.side == 0)
		m->v.wallx = m->pos.y + m->v.wall_dist * m->v.ray_y;
	else
		m->v.wallx = m->pos.x + m->v.wall_dist * m->v.ray_x;
	m->v.wallx -= floor((m->v.wallx));
	if (m->v.side == 0 && m->v.ray_x < 0)
		m->v.texture = m->tex[0];
	if (m->v.side == 0 && m->v.ray_x > 0)
		m->v.texture = m->tex[1];
	if (m->v.side == 1 && m->v.ray_y < 0)
		m->v.texture = m->tex[2];
	if (m->v.side == 1 && m->v.ray_y > 0)
		m->v.texture = m->tex[3];
}

void		raycasting_texture_2(t_main *m)
{
	m->v.tex_x = (int)(m->v.wallx * (double)m->v.texture.w);
	if (m->v.side == 0 && m->v.ray_x > 0)
		m->v.tex_x = m->v.texture.w - m->v.tex_x - 1;
	if (m->v.side == 1 && m->v.ray_y < 0)
		m->v.tex_x = m->v.texture.w - m->v.tex_x - 1;
	m->v.step = 1.0 * m->v.texture.h / m->v.line_h;
	m->v.tex_pos = (m->v.draw_start - m->h / 2 + m->v.line_h / 2) * m->v.step;
}

void		raycasting_texture_3(t_main *m, double *z_buffer)
{
	m->v.a = -1;
	while (++m->v.a < m->h / 2)
	{
		m->v.dst = m->img.data +
			(m->v.a * m->img.len + m->v.i * (m->img.bpp / 8));
		*(unsigned int *)m->v.dst = m->color.c;
	}
	while (++m->v.a < m->h)
	{
		m->v.dst = m->img.data + (m->v.a * m->img.len +
			m->v.i * (m->img.bpp / 8));
		*(unsigned int *)m->v.dst = m->color.f;
	}
	raycasting_texture_4(m);
	z_buffer[m->v.i] = m->v.wall_dist;
}

void		raycasting_texture_4(t_main *m)
{
	while (m->v.draw_start < m->v.draw_end)
	{
		m->v.tex_y = (int)m->v.tex_pos & (m->v.texture.h - 1);
		m->v.tex_pos += m->v.step;
		m->v.color =
			m->v.texture.data[m->v.texture.w * m->v.tex_x + m->v.tex_y];
		m->v.dst = m->img.data +
			(m->v.draw_start * m->img.len + m->v.i * (m->img.bpp / 8));
		*(unsigned int *)m->v.dst = m->v.color;
		++m->v.draw_start;
	}
}

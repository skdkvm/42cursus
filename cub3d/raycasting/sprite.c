/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:18:03 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/31 16:11:59 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_distance(t_main *m, t_sort *sprite_sort)
{
	sprite_sort[m->v.i].order = m->v.i;
	sprite_sort[m->v.i].distance =
		((m->pos.x - m->sp[m->v.i].x) * (m->pos.x - m->sp[m->v.i].x) +
		(m->pos.y - m->sp[m->v.i].y) * (m->pos.y - m->sp[m->v.i].y));
}

void	sort_sprites(t_main *m, t_sort *sprite_sort)
{
	t_sort	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < m->map.spr - 1)
	{
		j = i + 1;
		while (j < m->map.spr)
		{
			if (sprite_sort[i].distance < sprite_sort[j].distance)
			{
				tmp = sprite_sort[i];
				sprite_sort[i] = sprite_sort[j];
				sprite_sort[j] = tmp;
			}
			j++;
		}
		i++;
	}
	m->v.i = -1;
}

void	sprite_set_info(t_main *m, t_sort *sprite_sort)
{
	m->v.num = sprite_sort[m->v.i].order;
	m->v.texture = m->tex[4];
	m->v.sprite_x = m->sp[m->v.num].x - m->pos.x;
	m->v.sprite_y = m->sp[m->v.num].y - m->pos.y;
	m->v.invdet =
		1.0 / (m->plane.x * m->dir.y - m->dir.x * m->plane.y);
	m->v.transform_x = m->v.invdet *
					(m->dir.y * m->v.sprite_x - m->dir.x * m->v.sprite_y);
	m->v.transform_y = m->v.invdet *
					(-m->plane.y * m->v.sprite_x + m->plane.x * m->v.sprite_y);
	m->v.sprite_screen_x =
		(int)((m->w / 2) * (1 + m->v.transform_x / m->v.transform_y));
	m->v.v_movescreen = (int)(V_MOVE / m->v.transform_y);
	m->v.sprite_h = abs((int)(m->h / (m->v.transform_y))) / V_DIV;
}

void	sprite_get_draw_info(t_main *m)
{
	m->v.drawstart_y = -m->v.sprite_h / 2 + m->h / 2 + m->v.v_movescreen;
	if (m->v.drawstart_y < 0)
		m->v.drawstart_y = 0;
	m->v.drawend_y = m->v.sprite_h / 2 + m->h / 2 + m->v.v_movescreen;
	if (m->v.drawend_y >= m->h)
		m->v.drawend_y = m->h - 1;
	m->v.sprite_w = abs((int)(m->h / (m->v.transform_y))) / U_DIV;
	m->v.drawstart_x = -m->v.sprite_w / 2 + m->v.sprite_screen_x;
	if (m->v.drawstart_x < 0)
		m->v.drawstart_x = 0;
	m->v.drawend_x = m->v.sprite_w / 2 + m->v.sprite_screen_x;
	if (m->v.drawend_x >= m->w)
		m->v.drawend_x = m->w - 1;
}

void	sprite_put_info(t_main *m, double *z_buffer)
{
	m->v.d_x = m->v.drawstart_x - 1;
	while (++m->v.d_x < m->v.drawend_x)
	{
		m->v.tex_x = (int)((m->v.d_x - (-m->v.sprite_w / 2 +
			m->v.sprite_screen_x)) * m->v.texture.w / m->v.sprite_w);
		if (m->v.transform_y > 0 && m->v.d_x > 0 && m->v.d_x < m->w &&
			m->v.transform_y < z_buffer[m->v.d_x])
		{
			m->v.d_y = m->v.drawstart_y - 1;
			while (++m->v.d_y < m->v.drawend_y)
			{
				m->v.d = (m->v.d_y - m->v.v_movescreen) -
				m->h / 2 + m->v.sprite_h / 2;
				m->v.tex_y = m->v.d * m->v.texture.h / m->v.sprite_h;
				m->v.color = m->v.texture.data[64 * m->v.tex_y + m->v.tex_x];
				if ((m->v.color & 0x00FFFFFF) != 0)
					m->v.dst = m->img.data +
						(m->v.d_y * m->img.len + m->v.d_x * (m->img.bpp / 8));
				*(unsigned int *)m->v.dst = m->v.color;
			}
		}
	}
}

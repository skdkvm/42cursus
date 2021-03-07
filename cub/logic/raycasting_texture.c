#include "../cub3d.h"

void ft_raycasting_put_texture_1(t_main *m)
{
	m->v.line_h = (int)(m->h / m->v.wall_dist); // 스크린에 그릴 line의 높이를 계산.
	/*
    이제 계산한 거리를 가지고 화면에 그려야 하는 선의 높이를 구할 수 있다.
	벽을 더 높게 그리거나 낮게 그리고 싶으면 2 * lineHeight 같은 값을 넣을 수도 있다.
    위에서 구한 lineHeight로부터 우리는 선을 그릴 위치의 시작점과 끝점을 구해낼 수 있다.
    만약에 벽의 범위 (0 ~ screenHeight)를 벗어나는 경우
    각각 0과 screenHeight - 1을 대입한다.
    +) drawStart와 End에 2로 나눈 값들을 더하는 이유는
    screenHeight보다 drawEnd가 커지면 될까 안될까를 생각해보면 알 수 있다.
    */
	m->v.draw_start = -m->v.line_h / 2 + m->h / 2;
	if (m->v.draw_start < 0)
		m->v.draw_start = 0;
	m->v.draw_end = m->v.line_h / 2 + m->h / 2;
	if (m->v.draw_end >= m->h)
		m->v.draw_end = m->h;

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

void ft_raycasting_put_texture_2(t_main *m)
{
	m->v.tex_x = (int)(m->v.wallx * (double)m->v.texture.w);
	if (m->v.side == 0 && m->v.ray_x > 0)
		m->v.tex_x = m->v.texture.w - m->v.tex_x - 1;
	if (m->v.side == 1 && m->v.ray_y < 0)
		m->v.tex_x = m->v.texture.w - m->v.tex_x - 1;
	m->v.step = 1.0 * m->v.texture.h / m->v.line_h;
	m->v.tex_pos = (m->v.draw_start - m->h / 2 + m->v.line_h / 2) * m->v.step;
}

void ft_raycasting_put_texture_3(t_main *m, double *z_buffer)
{
	m->v.a = -1;
	while (++m->v.a < m->h / 2)
	{
		m->v.dst = m->img.data + (m->v.a * m->img.len + m->v.i * (m->img.bpp / 8));
		*(unsigned int *)m->v.dst = m->color.c;
	}
	while (++m->v.a < m->h)
	{
		m->v.dst = m->img.data + (m->v.a * m->img.len + m->v.i * (m->img.bpp / 8));
		*(unsigned int *)m->v.dst = m->color.f;
	}
	while (m->v.draw_start < m->v.draw_end)
	{
		m->v.tex_y = (int)m->v.tex_pos & (m->v.texture.h - 1);
		m->v.tex_pos += m->v.step;
		m->v.color =
			m->v.texture.data[m->v.tex_x * m->v.texture.w + m->v.tex_y];
		m->v.dst = m->img.data +
				   (m->v.draw_start * m->img.len + m->v.i * (m->img.bpp / 8));
		*(unsigned int *)m->v.dst = m->v.color;
		++m->v.draw_start;
	}
	z_buffer[m->v.i] = m->v.wall_dist;
}

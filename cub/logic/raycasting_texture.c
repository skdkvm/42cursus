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
	이 값은 텍스처를 적용할 때 어떤 x좌표를 사용해야 하는지 판단할 때 사용할 것입니다.
	우선 부딪힌 곳의 정확한 x, y값(double)에서 벽의 x, y값(int)을 빼서 판단할 수 있습니다.
	변수 wallX 는 x면과 부딪힌 경우(side == 0)인 경우 이름에서 유추할 수 있듯 벽의 x좌표가 맞지만, y면에 부딪힌 경우(side == 1)에는 벽의 y좌표가 된다는 점에 유의하세요.
	이러나 저러나 텍스처를 적용할 때 wallX 의 값은 텍스처의 x좌표에 사용됩니다.
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
/*
여기서 step을 사용한 방식은 아핀 텍스처매핑 방법입니다.
각 픽셀에 대해 각각 나눗셈을 하지않고 두 점 사이를 선형보간하는 방식입니다. 이 방법은 일반적으로 원근법을 정확하게 표현해주지 못하지만 지금처럼 완벽하게 수직인 벽(그리고 완벽하게 수평인 천장과 바닥)인 경우에는 올바르게 나타납니다.
*/
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

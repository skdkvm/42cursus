#include "../cub3d.h"

void ft_find_pos_two(t_main *m, char c)
{
	if (c == 'S') //남쪽 이라면
	{
		m->dir.x = 1;
		m->plane.x = 0;
		m->plane.y = -PLANE;
	}
	if (c == 'E') //동쪽 이라면
	{
		m->dir.x = 0;
		m->dir.y = 1;
		m->plane.x = PLANE;
		m->plane.y = 0;
	}
	if (c == 'W') //서쪽 이라면
	{
		m->dir.x = 0;
		m->dir.y = -1;
		m->plane.x = -PLANE;
		m->plane.y = 0;
	}
}

void ft_find_pos(t_main *m, char c, int i, int j)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && m->map.user == 0) //만약에 c가 북 or 남 or 동 or 서 그리고 map에 user가 0이라면 x,y의 위치에 유저를 생성해라
	{
		m->pos.x = (double)i + 0.5;
		m->pos.y = (double)j + 0.5;
		m->map.user = 1;
	}
	else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && m->map.user != 0) //만약에 c가 북 or 남 or 동 or 서 그리고 map에 user가 0이 아니라면 에러 처리
	{
		ft_free_array(m->map.map);
		ft_put_massage(9); //user 의 num == 1이 아니다 에러 처리
	}
	if (c == 'N') //c가 N이라면
	{
		m->dir.x = -1;
		m->dir.y = 0;
		m->plane.x = 0;
		m->plane.y = PLANE;
	}
	ft_find_pos_two(m, c);
}

void ft_put_sprite(t_main *m)
{
	int i;
	int j;
	int k;

	if (!(m->sp = (t_sprite *)malloc((m->map.spr + 1) * sizeof(t_sprite))))
		ft_put_massage(14); //동적 할당이 잘못 됨 에러 출력
	i = -1;
	k = -1;
	while (++i < m->map.x)
	{
		j = -1;
		while (++j < m->map.y)
		{
			if (m->map.map[i][j] == '2')
			{
				++k;
				m->sp[k].x = (double)i + 0.5;
				m->sp[k].y = (double)j + 0.5;
			}
		}
	}
}

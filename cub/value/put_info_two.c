#include "../cub3d.h"

void ft_find_pos_two(t_main *m, char c)
{
	if (c == 'S')
	{
		m->dir.x = 1;
		m->dir.y = 0;
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

void ft_find_pos(t_main *m, char c, int i, int j)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && m->map.user == 0)
	{
		m->pos.x = (double)i + 0.5;
		m->pos.y = (double)j + 0.5;
		m->map.user = 1;
	}
	else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && m->map.user != 0)
	{
		ft_free_array(m->map.map);
		ft_put_massage(9);
	}
	if (c == 'N')
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
		ft_put_massage(14);
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

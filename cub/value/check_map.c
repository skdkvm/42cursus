#include "../cub3d.h"

int ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void ft_check_map_user(t_main *m)
{
	if (m->map.user == 0)
	{
		ft_free_array(m->map.map);
		ft_put_massage(10);
	}
}

void ft_check_map_wall(t_main *m, int i, int j)
{
	if (i == 0 || j == 0 || i == m->map.x - 1 || j == m->map.y - 1)
	{
		if (!(m->map.map[i][j] == '1' || (i == 0 && m->map.map[i][j] == 'n') || (j == 0 && m->map.map[i][j] == 'n') || (i == m->map.x - 1 && m->map.map[i][j] == 'n') || (j == m->map.y - 1 && m->map.map[i][j] == 'n')))
		{
			ft_free_array(m->map.map);
			ft_put_massage(7);
		}
	}
	else
	{
		if ((m->map.map[i][j] == '0' || m->map.map[i][j] == '2' || m->map.map[i][j] == 'N' || m->map.map[i][j] == 'E' || m->map.map[i][j] == 'S' || m->map.map[i][j] == 'W') && (m->map.map[i - 1][j] == 'n' || m->map.map[i + 1][j] == 'n' || m->map.map[i][j + 1] == 'n'))
		{
			ft_free_array(m->map.map);
			ft_put_massage(7);
		}
	}
}

void ft_check_map(t_main *m)
{
	int i;
	int j;

	if (m->map.x < 3 || m->map.y < 3)
	{
		ft_free_array(m->map.map);
		ft_put_massage(8);
	}
	i = -1;
	while (++i < m->map.x)
	{
		j = -1;
		while (++j < m->map.y)
		{
			ft_check_map_wall(m, i, j);
			ft_find_pos(m, m->map.map[i][j], i, j);
			if (m->map.map[i][j] == '2')
				++m->map.spr;
		}
	}
	ft_check_map_user(m);
	ft_put_sprite(m);
}

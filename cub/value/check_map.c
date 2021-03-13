#include "../cub3d.h"
#include <stdio.h>

int ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void ft_check_map_user(t_main *m) //맵에 유저가 있는가
{
	if (m->map.user == 0)
	{
		ft_free_array(m->map.map);
		ft_put_massage(10); //맵에 유저가 없다 에러 출력
	}
}

void ft_check_map_wall(t_main *m, int i, int j) //벽이 제대로 1로 둘러쌓여 있는가 체크
{
	if (i == 0 || j == 0 || i == m->map.x - 1 || j == m->map.y - 1)
	{
		if (!(m->map.map[i][j] == '1' || (i == 0 && m->map.map[i][j] == 'n') || (j == 0 && m->map.map[i][j] == 'n') || (i == m->map.x - 1 && m->map.map[i][j] == 'n') || (j == m->map.y - 1 && m->map.map[i][j] == 'n')))
		{
			ft_free_array(m->map.map);
			ft_put_massage(7); //wall '1'이 아니다 에러 출력
		}
	}
	else
	{
		if ((m->map.map[i][j] == '0' || m->map.map[i][j] == '2' || m->map.map[i][j] == 'N' || m->map.map[i][j] == 'E' || m->map.map[i][j] == 'S' || m->map.map[i][j] == 'W') && (m->map.map[i - 1][j] == 'n' || m->map.map[i + 1][j] == 'n' || m->map.map[i][j + 1] == 'n'))
		{
			ft_free_array(m->map.map);
			ft_put_massage(7); //wall '1'이 아니다 에러 출력
		}
	}
}

void ft_check_map(t_main *m)
{
	int i;
	int j;

	if (m->map.x < 3 || m->map.y < 3) //맵이 3x3보다 작다면 맵이 유저를 감싸지 않아서 에러
	{
		ft_free_array(m->map.map);
		ft_put_massage(8); //map이 너무 작음 에러 출력
	}
	i = -1;
	while (++i < m->map.x)
	{
		j = -1;
		while (++j < m->map.y)
		{
			ft_check_map_wall(m, i, j);				//벽이 제대로 감싸고 있는지 체크
			ft_find_pos(m, m->map.map[i][j], i, j); //유저의 위치 찾는 함수
			if (m->map.map[i][j] == '2')			//맵이 2일경우 장애물?
				++m->map.spr;						//스플릿에 ++
		}
	}
	ft_check_map_user(m); //맵에 유저가 있는지 체크
	ft_put_sprite(m);	  //장애물 넣기
}

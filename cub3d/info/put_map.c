/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:37:39 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/13 16:38:30 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*put_map_value(char *line, int len, int y)
{
	int		i;
	char	*value;
	printf("line = %s\n", line); //line 맵 정보가 들어가있음
	if (!(value = (char *)malloc((y + 1) * sizeof(char))))
		error_write(14);
	i = -1;
	while (++i < y)
	{
		value[i] = 'n';
		//printf("value[i] = %c\n", value[i]); //전부 n값을 넣어준다
	}
	i = -1;
	while (++i < len)
	{
		if (!(ft_isspace(line[i])))
			value[i] = line[i];
	}
	value[y] = 0;
	return (value);
}

void	copy_map(char **dest, char **array, int x, t_main *m)
{
	int i;

	i = -1;
	while (++i < x)
	{
		dest[i] = put_map_value(array[i], m->y, m->map.y);
		printf("dest = %s\n", dest[i]); //맵을 한줄씩 복제
	}
	dest[x] = 0;
}

void	check_map_value(char *line)
{
	while (*line)
	{
		if (!((*line >= '0' || *line <= '2' || *line == 'N' ||
				*line == 'S' || *line == 'W' || *line == 'E' ||
			ft_isspace(*line) || *line == 0)))
			error_write(11);
		line++;
	}
}

void	put_map(t_main *m, char *line, int *x, int *y)
{
	check_map_value(line);
	printf("check_map_value = %s\n", line);//맵의 정보가 들어가있다
	m->len = ft_strlen(line);
	m->x = *x;
	printf("x = %d\n", *x); //맵의 행의 개수
	m->y = *y;
	printf("y = %d\n", *y); //맵의 열의 개수
	if (*y < m->len)
		*y = m->len;
	++(*x);
	if (m->map.map != NULL)//맵이 NULL아니면 tem에 map.map을 copy
	{
		if (!(m->map.tem = (char **)malloc((m->x + 1) * sizeof(char *))))
			error_write(14);
		copy_map(m->map.tem, m->map.map, m->x, m);
		free_array(m->map.map);
		m->cub.map = 1;
	}
	if (!(m->map.map = (char **)malloc((*x + 1) * sizeof(char *))))
		error_write(14);
	if (m->cub.map != 0)//cub.map이 0이 아니면 맵을 copy
	{
		copy_map(m->map.map, m->map.tem, *x - 1, m);
		free_array(m->map.tem);
	}
	m->map.map[*x - 1] = put_map_value(line, m->len, *y);
	printf("put_map_value = %s\n", m->map.map[*x - 1]); //맵의 정보가 모두 copy가 잘됨
	m->map.map[*x] = 0;
}

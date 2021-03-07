#include "../cub3d.h"

char *ft_put_map_value(char *line, int len, int y)
{
	int i;
	char *value;

	if (!(value = (char *)malloc((y + 1) * sizeof(char))))
		ft_put_massage(14);
	i = -1;
	while (++i < y)
		value[i] = 'n';
	i = -1;
	while (++i < len)
	{
		if (!(ft_isspace(line[i])))
			value[i] = line[i];
	}
	value[y] = 0;
	return (value);
}

void ft_copy_map(char **dest, char **array, int x, t_main *m)
{
	int i;

	i = -1;
	while (++i < x)
		dest[i] = ft_put_map_value(array[i], m->y, m->map.y);
	dest[x] = 0;
}

void ft_check_map_value(char *line)
{
	while (*line)
	{
		if (!((*line >= '0' && *line <= '2') || *line == 'N' || *line == 'S' || *line == 'W' || *line == 'E' ||
			  ft_isspace(*line) || *line == 0))
			ft_put_massage(11);
		line++;
	}
}

void ft_put_map(t_main *m, char *line, int *x, int *y)
{
	ft_check_map_value(line);
	m->len = ft_strlen(line);
	m->x = *x;
	m->y = *y;
	if (*y < m->len)
		*y = m->len;
	++(*x);
	if (m->map.map != NULL)
	{
		if (!(m->map.tem = (char **)malloc((m->x + 1) * sizeof(char *))))
			ft_put_massage(14);
		ft_copy_map(m->map.tem, m->map.map, m->x, m);
		ft_free_array(m->map.map);
		m->cub.map = 1;
	}
	if (!(m->map.map = (char **)malloc((*x + 1) * sizeof(char *))))
		ft_put_massage(14);
	if (m->cub.map != 0)
	{
		ft_copy_map(m->map.map, m->map.tem, *x - 1, m);
		ft_free_array(m->map.tem);
	}
	m->map.map[*x - 1] = ft_put_map_value(line, m->len, *y);
	m->map.map[*x] = 0;
}

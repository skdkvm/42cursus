// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:37:34 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/13 16:33:51 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_map_size(t_main *m, char *line)
{
	char	**array;

	array = ft_split_line(line);
	printf("array = %s\n", line); //line = R 800 600 정보가 들어가 있음
	printf("array[1] = %s\n", array[0]);// array[0] = R;
	printf("array[1] = %s\n", array[1]);// array[1] = 800;
	printf("array[2] = %s\n", array[2]);// array[2] = 600;
	printf("array[3] = %s\n", array[3]);// array[3] = (null);
	if (!(array[1] != 0 && array[2] != 0) || m->cub.r != 0 || array[3] != 0)
	{
		free_array(array);
		error_write(4);
	}
	m->w = ft_atoi(array[1]);
	m->h = ft_atoi(array[2]);
	if (m->w > 2048 || m->w < 1)
		m->w = 2048;
	if (m->h > 1280 || m->h < 1)
		m->h = 1280;
	m->cub.r = 1;
	++m->cub.all;
	m->win = mlx_new_window(m->mlx, m->w, m->h, "cub3D");
	free_array(array);
}

void	put_background(t_main *m, char *line, int c, int *cub)
{
	int		i;
	char	**array;

	i = 0;
	array = ft_split_line(line);
	printf("array = %s\n", line);// line = F 102,51,0 / C 64,64,64
	printf("array[1] = %s\n", array[1]);// F : R = 102 / C : R = 64
	printf("array[2] = %s\n", array[2]);// F : G = 51 / C : G = 64
	printf("array[3] = %s\n", array[3]);// F : B = 51 / C : B = 64
	while (++i < 4)
	{
		if (array[i] == NULL || *cub != 0 ||
			(ft_atoi(array[i]) < 0 || ft_atoi(array[i]) > 255))
		{
			free_array(array);
			error_write(6);
		}
	}
	(*cub) = 1;
	++m->cub.all;
	if (c == 'C')
		m->color.c = (ft_atoi(array[1]) << 16) +
		(ft_atoi(array[2]) << 8) + ft_atoi(array[3]);
	if (c == 'F')
		m->color.f = (ft_atoi(array[1]) << 16) +
		(ft_atoi(array[2]) << 8) + ft_atoi(array[3]);
	free_array(array);
}

void	put_texture(t_main *m, char *line, int i, int *cub)
{
	char	**array;
	int		fd;

	array = ft_split_line(line);
	printf("array = %s\n", line);// texture 정보
	fd = open(array[1], O_RDONLY);
	if (fd == -1 || (*cub) != 0)
	{
		free_array(array);
		close(fd);
		error_write(5);
	}
	(*cub) = 1;
	++m->cub.all;
	m->tex[i].img =
		mlx_xpm_file_to_image(m->mlx, array[1], &m->tex[i].w, &m->tex[i].h);
	m->tex[i].data = (int *)mlx_get_data_addr(m->tex[i].img, &m->tex[i].bpp,
											&m->tex[i].len, &m->tex[i].endian);
	free_array(array);
}

void	put_sprite(t_main *m)
{
	int	i;
	int	j;
	int	k;

	if (!(m->sp = (t_sprite *)malloc((m->map.spr + 1) * sizeof(t_sprite))))
		error_write(14);
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

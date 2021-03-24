/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:45:12 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/24 21:28:20 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		put_map_size(t_main *m, char *line)
{
	char	**array;

	array = ft_split_line(line);
	if (!(array[1] != 0 && array[2] != 0) || m->cub.r != 0 || array[3] != 0)
	{
		free_array(array);
		error_write(4);
	}
	m->w = ft_atoi(array[1]);
	m->h = ft_atoi(array[2]);
	if (m->w > 2560 || m->w < 1)
		m->w = 2560;
	if (m->h > 1400 || m->h < 1)
		m->h = 1400;
	m->cub.r = 1;
	++m->cub.all;
	m->win = mlx_new_window(m->mlx, m->w, m->h, "cub3D");
	free_array(array);
}

void		put_texture(t_main *m, char *line, int i, int *cub)
{
	char	**array;
	int		fd;

	array = ft_split_line(line);
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
	m->tex[i].data =
				(int *)mlx_get_data_addr(m->tex[i].img, &m->tex[i].bpp,
									&m->tex[i].len, &m->tex[i].endian);
	free_array(array);
}

void		put_background(t_main *m, char *line, int c, int *cub)
{
	int		i;
	char	**array;

	i = 0;
	array = ft_split_line(line);
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
		m->color.c = (ft_atoi(array[1]) << 16)
				+ (ft_atoi(array[2]) << 8) + ft_atoi(array[3]);
	if (c == 'F')
		m->color.f = (ft_atoi(array[1]) << 16)
				+ (ft_atoi(array[2]) << 8) + ft_atoi(array[3]);
	free_array(array);
}

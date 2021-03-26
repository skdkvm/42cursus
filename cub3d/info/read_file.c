/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:37:44 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/26 16:29:57 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_all_info(t_main *m)
{
	if (m->cub.all != 8 || m->map.map == 0)
	{
		error_write(13);
	}
}

void	check_name(char *filename, char *str)
{
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(filename);
	if (len > 4)
	{
		while (++i < 4)
		{
			if (filename[len - 4 + i] != str[i])
				error_write(1);
		}
	}
	else
		error_write(1);
}

void	check_save(t_main *m, char *save, char *str)
{
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(save);
	if (len == 6)
	{
		while (++i < len)
		{
			if (save[i] != str[i])
				error_write(2);
		}
		m->save = 1;
	}
	else
		error_write(2);
}

void	save_info(t_main *m, char *line, int i)
{
	if (m->cub.all == 8)
		put_map(m, line, &m->map.x, &m->map.y);
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		(i)++;
	if (line[i] == 'R' && ft_isspace(line[i + 1]))
		put_map_size(m, line);
	if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		put_texture(m, line, 0, &m->cub.n);
	if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		put_texture(m, line, 1, &m->cub.s);
	if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		put_texture(m, line, 2, &m->cub.w);
	if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		put_texture(m, line, 3, &m->cub.e);
	if (line[i] == 'S' && line[i + 1] == 'P')
		put_texture(m, line, 4, &m->cub.sp);
	if (line[i] == 'S' && line[i + 1] == 'P' && line[i + 2] == 'P')
		put_texture(m, line, 4, &m->cub.sp);
	if (line[i] == 'F' && ft_isspace(line[i + 1]))
		put_background(m, line, 'F', &m->cub.f);
	if (line[i] == 'C' && ft_isspace(line[i + 1]))
		put_background(m, line, 'C', &m->cub.c);
}

void	read_file(t_main *m, int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	check_name(av[1], ".cub");
	if (ac == 3)
		check_save(m, av[2], "--save");
	ret = 1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_write(0);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		m->cub.i = 0;
		save_info(m, line, m->cub.i);
		free(line);
	}
	check_all_info(m);
	check_map(m);
	close(fd);
	if (ret == -1)
		error_write(3);
}

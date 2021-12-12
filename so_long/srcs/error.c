/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:06:00 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:16:03 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	error_map_name(char *map, t_info *info)
{
	int	size;

	if (!info)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 2);
		exit(EXIT_FAILURE);
	}
	size = ft_strlen(map);
	if (size < 4 || ft_strcmp(map + (size - 4), ".ber"))
	{
		ft_putstr_fd("Error\nMap format is incorrect\n", 2);
		free_info(info);
		exit(EXIT_FAILURE);
	}
}

static void	handle_line(char *line, t_info *info)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(line));
	if (!new || !(new->content))
		close_error(line, info);
	ft_lstadd_back(&(info->map_ptr), new);
}

static void	read_file(int fd, t_info *info)
{
	int		ret;
	char	*line;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (line && *line)
			handle_line(line, info);
		free(line);
		if (ret == 0)
			break ;
		if (ret == -1)
		{
			ft_putstr_fd("Error\nreading error\n", 2);
			close(fd);
			free_info(info);
			exit(EXIT_FAILURE);
		}
	}
}

static void	open_file(char *map, t_info *info)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(map, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free_info(info);
		exit(EXIT_FAILURE);
	}
	read_file(fd, info);
	close(fd);
}

t_info	*ft_parsing(char *map)
{
	t_info	*info;
	int		len;

	info = ft_calloc(1, sizeof(t_info));
	error_map_name(map, info);
	open_file(map, info);
	if (info->map_ptr)
		len = ft_strlen((char *)info->map_ptr->content);
	if (ft_lstsize(info->map_ptr) < 3 || len < 3)
	{
		ft_putstr_fd("Error\nMap is too small\n", 2);
		free_info(info);
		exit(EXIT_FAILURE);
	}
	parse_map(info);
	if (info->player != 1 || !info->collect || !info->exit)
	{
		ft_putstr_fd("Error\nYour map doesn't fill the requirements\n", 2);
		free_info(info);
		exit(EXIT_FAILURE);
	}
	return (info);
}

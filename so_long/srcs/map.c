/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:05:41 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:13:07 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_good_texture(t_info *info, char c, int pos, int line)
{
	if (c == '0')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr,
			info->fl_texture->texture, pos, line);
	}
	if (c == '1')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr,
			info->wa_texture->texture, pos, line);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr,
			info->pl_texture->texture, pos, line);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr,
			info->co_texture->texture, pos, line);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr,
			info->ex_texture->texture, pos, line);
	}
}

void	display_line(t_info *info, char *str, int line)
{
	int	pos;

	pos = 0;
	while (*str)
	{
		display_good_texture(info, *str, pos, line);
		str++;
		pos += 64;
	}
}

void	display_map(t_info *info)
{
	int		line;
	t_list	*tmp;

	line = 0;
	tmp = info->map_ptr;
	while (tmp)
	{
		display_line(info, (char *)tmp->content, line);
		tmp = tmp->next;
		line += 64;
	}
}

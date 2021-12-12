/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:06:27 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:23:42 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_texture(void *mlx_ptr, t_texture *texture)
{
	if (texture)
	{
		if (texture->texture)
			mlx_destroy_image(mlx_ptr, texture->texture);
		free(texture);
	}
}

static t_texture	*get_texture(char *file, t_info *info)
{
	int			data[3];
	t_texture	*img;

	img = ft_calloc(1, sizeof(t_texture));
	if (!img)
		close_error(NULL, info);
	img->texture = mlx_xpm_file_to_image(info->mlx_ptr, file,
			&img->width, &img->height);
	if (img->texture)
	{
		data[0] = 0;
		data[1] = 0;
		data[2] = 0;
		img->data = mlx_get_data_addr(img->texture, &data[0], &data[1],
				&data[2]);
	}
	return (img);
}

void	load_textures(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		close_error(NULL, info);
	info->fl_texture = get_texture("./texture/floor.xpm", info);
	info->wa_texture = get_texture("./texture/wall.xpm", info);
	info->pl_texture = get_texture("./texture/player.xpm", info);
	info->co_texture = get_texture("./texture/collectible.xpm", info);
	info->ex_texture = get_texture("./texture/exit.xpm", info);
}

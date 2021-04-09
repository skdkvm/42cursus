/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:13:37 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/09 10:22:45 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			cub_close(t_main *m)
{
	system("killall afplay");
	free_array(m->map.map);
	free(m->sp);
	exit(0);
	return (0);
}

int			key_press(int keycode, t_main *m)
{
	key_up_down(keycode, m);
	key_left_right(keycode, m);
	key_rotate(keycode, m);
	return (0);
}

int			main_loop(t_main *m)
{
	double	z_buffer[m->w];
	t_sort	sprite_sort[m->map.spr];

	m->v.i = -1;
	while (++m->v.i < m->w)
	{
		raycasting_set(m);
		raycasting_side_xy(m);
		raycasting_map_xy(m);
		raycasting_texture_1(m);
		raycasting_texture_2(m);
		raycasting_texture_3(m, z_buffer);
	}
	m->v.i = -1;
	while (++m->v.i < m->map.spr)
		sprite_distance(m, sprite_sort);
	sort_sprites(m, sprite_sort);
	while (++m->v.i < m->map.spr)
	{
		sprite_set_info(m, sprite_sort);
		sprite_get_draw_info(m);
		sprite_put_info(m, z_buffer);
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img.img, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_main	m;

	m.mlx = mlx_init();
	init_info(&m);
	read_file(&m, ac, av);
	if (ac != 2 && ac != 3)
		error_write(0);
	m.img.img = mlx_new_image(m.mlx, m.w, m.h);
	m.img.data =
		mlx_get_data_addr(m.img.img, &m.img.bpp, &m.img.len, &m.img.endian);
	mlx_loop_hook(m.mlx, &main_loop, &m);
	run_bgm();
	mlx_hook(m.win, 17, 0, &cub_close, &m);
	mlx_hook(m.win, 2, 1L << 0, key_press, &m);
	if (m.save == 1)
		bitmap(&m);
	mlx_loop(m.mlx);
	return (0);
}

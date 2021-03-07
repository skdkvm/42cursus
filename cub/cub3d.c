#include "cub3d.h"

int ft_close(t_main *m)
{
	ft_free_array(m->map.map);
	free(m->sp);
	exit(0);
	return (0);
}

int ft_key_press(int keycode, t_main *m)
{
	ft_keypress_up_down(keycode, m);
	ft_keypress_left_right(keycode, m);
	ft_keypress_rotate(keycode, m);
	return (0);
}

int main_loop(t_main *m)
{
	double z_buffer[m->w];
	t_sort sprite_sort[m->map.spr];

	m->v.i = -1;
	while (++m->v.i < m->w)
	{
		ft_raycasting_set_info(m);
		ft_raycasting_get_side_xy(m);
		ft_raycasting_get_map_xy(m);
		ft_raycasting_put_texture_1(m);
		ft_raycasting_put_texture_2(m);
		ft_raycasting_put_texture_3(m, z_buffer);
	}
	m->v.i = -1;
	while (++m->v.i < m->map.spr)
		ft_sprite_distance(m, sprite_sort);
	ft_sort_sprites(m, sprite_sort);
	while (++m->v.i < m->map.spr)
	{
		ft_sprite_set_info(m, sprite_sort);
		ft_sprite_get_draw_info(m);
		ft_sprite_put_info(m, z_buffer);
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img.img, 0, 0);
	return (0);
}

int main(int ac, char **av)
{
	t_main m;

	if (ac != 2 && ac != 3)
		ft_put_massage(0);
	m.mlx = mlx_init();
	ft_init_info(&m);
	ft_read_file(&m, ac, av);
	mlx_hook(m.win, 17, 0, &ft_close, &m);
	mlx_hook(m.win, 2, 1L << 0, ft_key_press, &m);
	m.img.img = mlx_new_image(m.mlx, m.w, m.h);
	m.img.data =
		mlx_get_data_addr(m.img.img, &m.img.bpp, &m.img.len, &m.img.endian);
	mlx_loop_hook(m.mlx, &main_loop, &m);
	if (m.save == 1)
		ft_bitmap(&m);
	mlx_loop(m.mlx);
	return (0);
}

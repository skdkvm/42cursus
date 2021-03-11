#include "cub3d.h"

int ft_close(t_main *m) //화면 닫기
{
	ft_free_array(m->map.map);
	free(m->sp);
	exit(0);
	return (0);
}

int ft_key_press(int keycode, t_main *m)
{
	ft_keypress_up_down(keycode, m);	//Key 입력 ESC W S
	ft_keypress_left_right(keycode, m); //Key 입력 A D
	ft_keypress_rotate(keycode, m);		//회전
	return (0);
}

int main_loop(t_main *m)
{
	double z_buffer[m->w];
	t_sort sprite_sort[m->map.spr];

	m->v.i = -1;
	while (++m->v.i < m->w) //인덱스가 width 값보다 커질때까지 반복
	{
		ft_raycasting_set_info(m);		//DDAgorithm 초기화
		ft_raycasting_get_side_xy(m);	//DDAgorithm을 시작하기 전에 stepX, Y 그리고 sideDistX, Y에 값을 넣어주는 부분이다.
		ft_raycasting_put_texture_1(m); //이제 계산한 거리를 가지고 화면에 그려야 하는 선의 높이를 구할 수 있다.
		ft_raycasting_put_texture_2(m); //여기서 step을 사용한 방식은 아핀 텍스처매핑 방법입니다. 각 픽셀에 대해 각각 나눗셈을 하지않고 두 점 사이를 선형보간하는 방식입니다.이 방법은 일반적으로 원근법을 정확하게 표현해주지 못하지만 지금처럼 완벽하게 수직인 벽(그리고 완벽하게 수평인 천장과 바닥) 인 경우에는 올바르게 나타납니다.ft_raycasting_put_texture_3(m, z_buffer);
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

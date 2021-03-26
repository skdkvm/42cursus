/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:16:54 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/26 16:33:39 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./Libft/libft.h"
# include "./gnl/get_next_line.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define PLANE 0.66
# define SPEED 0.3
# define ROTATE 0.25

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

typedef struct		s_bmp
{
	int				size;
	char			*img;
	int				fd;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	color[4];
}					t_bmp;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				w;
	int				h;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef struct		s_texture
{
	void			*img;
	int				*data;
	int				w;
	int				h;
	int				bpp;
	int				len;
	int				endian;
	char			*path;
}					t_texture;

typedef struct		s_dda_var
{
	int				i;
	double			camera_x;
	double			ray_x;
	double			ray_y;
	int				map_x;
	int				map_y;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	double			wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	t_texture		texture;
	double			wallx;
	int				tex_x;
	int				tex_y;
	unsigned		color;
	double			step;
	double			tex_pos;
	int				a;
	char			*dst;
	int				num;
	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				v_movescreen;
	int				sprite_w;
	int				sprite_h;
	int				drawstart_x;
	int				drawend_x;
	int				drawstart_y;
	int				drawend_y;
	int				d;
	int				d_x;
	int				d_y;
}					t_dda_var;

typedef struct		s_map
{
	char			**map;
	char			**tem;
	int				x;
	int				y;
	int				checkend;
	int				user;
	int				spr;
	int				spr2;
}					t_map;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_dir
{
	double			x;
	double			y;
}					t_dir;

typedef struct		s_plane
{
	double			x;
	double			y;
}					t_plane;

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_sprite2
{
	double			x;
	double			y;
}					t_sprite2;

typedef struct		s_sort
{
	int				order;
	double			distance;
}					t_sort;

typedef struct		s_color
{
	unsigned int	f;
	unsigned int	c;
}					t_color;

typedef struct		s_cub
{
	int				i;
	int				r;
	int				e;
	int				w;
	int				n;
	int				s;
	int				sp;
	int				sp2;
	int				f;
	int				c;
	int				map;
	int				all;
}					t_cub;

typedef struct		s_main
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	int				save;
	int				num_sprite;
	int				x;
	int				y;
	int				len;
	t_img			img;
	t_texture		tex[6];
	t_map			map;
	t_pos			pos;
	t_dir			dir;
	t_plane			plane;
	t_dda_var		v;
	t_sprite		*sp;
	t_sprite2		*sp2;
	t_color			color;
	t_cub			cub;
}					t_main;

void				init_info(t_main *m);
void				free_array(char **array);
void				read_file(t_main *m, int ac, char **av);
void				error_write(int num);
int					get_next_line(int fd, char **line);
char				**ft_split_line(char *str);
int					main_loop(t_main *m);
void				put_map_size(t_main *m, char *line);
void				put_texture(t_main *m, char *line, int i, int *cub);
void				put_background(t_main *m, char *line, int c, int *cub);
void				put_map(t_main *m, char *line, int *x, int *y);
void				put_sprite(t_main *m);
void				find_pos(t_main *m, char c, int i, int j);
int					ft_isspace(char c);
void				check_map(t_main *m);
void				check_map_user(t_main *m);
void				check_map_end(t_main *m, char *line);
void				check_map_wall(t_main *m, int i, int j);
void				key_up_down(int keycode, t_main *m);
void				key_left_right(int keycode, t_main *m);
void				key_rotate(int keycode, t_main *m);
void				raycasting_set(t_main *m);
void				raycasting_side_xy(t_main *m);
void				raycasting_map_xy(t_main *m);
void				raycasting_texture_1(t_main *m);
void				raycasting_texture_2(t_main *m);
void				raycasting_texture_3(t_main *m, double *z_buffer);
void				sprite_distance(t_main *m, t_sort *sprite_sort);
void				sort_sprites(t_main *m, t_sort *sprite_sort);
void				sprite_set_info(t_main *m, t_sort *sprite_sort);
void				sprite_set_info_2(t_main *m, t_sort *sprite_sort);
void				sprite_get_draw_info(t_main *m);
void				sprite_put_info(t_main *m, double *z_buffer);
void				bitmap(t_main *m);

#endif

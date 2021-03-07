#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124

#define PLANE 0.66
#define SPEED 0.3
#define ROTATE 0.25

#define U_DIV 1
#define V_DIV 1
#define V_MOVE 0.0

typedef struct s_bmp
{
	int size;
	char *img;
	int fd;
	unsigned char header[14];
	unsigned char info[40];
	unsigned char color[4];
} t_bmp;

typedef struct s_img
{
	void *img;
	char *data;
	int w;	 //width
	int h;	 //height
	int bpp; //파일
	int len;
	int endian;
} t_img;

typedef struct s_texture
{
	void *img;
	int *data;
	int w;
	int h;
	int bpp;
	int len;
	int endian;
	char *path;
} t_texture;

typedef struct s_dda_var
{
	int i;
	double camera_x;
	double ray_x;
	double ray_y;
	int map_x;
	int map_y;
	double side_x;
	double side_y;
	double delta_x;
	double delta_y;
	double wall_dist;
	int step_x;
	int step_y;
	int hit;
	int side;
	int line_h;
	int draw_start;
	int draw_end;
	t_texture texture;
	double wallx;
	int tex_x;
	unsigned color;
	double step;
	int tex_y;
	double tex_pos;
	int a;
	char *dst;
	int num;
	double sprite_x;
	double sprite_y;
	double invdet;
	double transform_x;
	double transform_y;
	int sprite_screen_x;
	int v_movescreen;
	int sprite_h;
	int drawstart_y;
	int drawend_y;
	int sprite_w;
	int drawstart_x;
	int drawend_x;
	int d_x;
	int d_y;
	int d;
} t_dda_var;

typedef struct s_map
{
	char **map;
	char **tem;
	int x;
	int y;
	int checkend;
	int user;
	int spr;
} t_map;

typedef struct s_pos
{
	double x; //x좌표
	double y; //y좌표
} t_pos;	  //유저 위치

typedef struct s_dir
{
	double x; //x좌표
	double y; //y좌표
} t_dir;

typedef struct s_plane
{
	double x; //x좌표
	double y; //y좌표
} t_plane;

typedef struct s_sprite
{
	double x; //x좌표
	double y; //y좌표
} t_sprite;	  //장애물

typedef struct s_sort
{
	int order;		 //요청?
	double distance; //거리
} t_sort;			 //분류

typedef struct s_color
{
	unsigned int f; //floor
	unsigned int c; //celling
} t_color;

typedef struct s_cub
{
	int i;	 // map.cub [i]인덱스
	int r;	 // 해상도
	int e;	 // 동쪽
	int w;	 // 서쪽
	int n;	 // 북쪽
	int s;	 // 남쪽
	int sp;	 // 장애물
	int f;	 // 바닥
	int c;	 // 천장
	int map; // 맵파일
	int all; // 변수 모든것
} t_cub;

typedef struct s_main
{
	void *mlx;		//mlx
	void *win;		//mlx widow
	int w;			//width
	int h;			//height
	int save;		//저장
	int num_sprite; //
	int x;			//x좌표
	int y;			//y좌표
	int len;		//길이?
	t_img img;
	t_texture tex[5]; //e,w,s,n,sp
	t_map map;
	t_pos pos;
	t_dir dir;
	t_plane plane;
	t_dda_var v;
	t_sprite *sp;
	t_color color;
	t_cub cub;
} t_main;

void ft_init_info(t_main *m);
void ft_read_file(t_main *m, int ac, char **av);
void ft_put_massage(int num);
int get_next_line(int fd, char **line);

char **ft_split_line(char *str);
void ft_free_array(char **array);

int main_loop(t_main *m);

void ft_put_map_size(t_main *m, char *line);
void ft_put_texture(t_main *m, char *line, int i, int *cub);
void ft_put_background(t_main *m, char *line, int c, int *cub);
void ft_put_map(t_main *m, char *line, int *x, int *y);
void ft_put_sprite(t_main *m);
void ft_find_pos(t_main *m, char c, int i, int j);

int ft_isspace(char c);
void ft_check_map(t_main *m);
void ft_check_map_user(t_main *m);
void ft_check_map_end(t_main *m, char *line);
void ft_check_map_wall(t_main *m, int i, int j);

void ft_keypress_up_down(int keycode, t_main *m);
void ft_keypress_left_right(int keycode, t_main *m);
void ft_keypress_rotate(int keycode, t_main *m);

void ft_raycasting_set_info(t_main *m);
void ft_raycasting_get_side_xy(t_main *m);
void ft_raycasting_get_map_xy(t_main *m);

void ft_raycasting_put_texture_1(t_main *m);
void ft_raycasting_put_texture_2(t_main *m);
void ft_raycasting_put_texture_3(t_main *m, double *z_buffer);

void ft_sprite_distance(t_main *m, t_sort *sprite_sort);
void ft_sort_sprites(t_main *m, t_sort *sprite_sort);

void ft_sprite_set_info(t_main *m, t_sort *sprite_sort);
void ft_sprite_get_draw_info(t_main *m);
void ft_sprite_put_info(t_main *m, double *z_buffer);

void ft_bitmap(t_main *m);
#endif

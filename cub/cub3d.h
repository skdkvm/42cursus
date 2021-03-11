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

#define PLANE 0.66	//카메라 평면 위치?
#define SPEED 0.3	//움직이는 속도
#define ROTATE 0.25 //회전행렬 속도[방향키로 회전 <- ->]

#define U_DIV 1	   //디비전?
#define V_DIV 1	   //디비전?
#define V_MOVE 0.0 //무브..?

typedef struct s_bmp
{
	int size;
	char *img;
	int fd;
	unsigned char header[14];
	unsigned char info[40];
	unsigned char color[4];
} t_bmp;
// get_img_data_addr 함수에서 쓸 변수를 갖고 있는 구조체.
typedef struct s_img
{
	void *img;
	char *data;
	int w;
	int h;
	int bpp;
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
//DDA 알고리즘 구조체
typedef struct s_dda_var
{
	int i;			 //인덱스
	double camera_x; //x값이 카메라 평면 상에 있을 때의 x좌표
	double ray_x;	 //현재 위치에서 다음 x사이드까지의 거리
	double ray_y;	 //현재 위치에서 다음 y사이드까지의 거리
	int map_x;		 //현재 player가 위치한 맵 내 위치
	int map_y;		 //현재 player가 위치한 맵 내 위치
	double side_x;	 //다음 map박스로 이동하거나 x방향으로 이동한다.
	double side_y;	 //다음 map박스로 이동하거나 y방향으로 이동한다.
	double delta_x;	 //delta_x 첫 번째 x면에서 그 다음 x면까지의 광선의 이동거리
	double delta_y;	 //delta_y 첫 번째 y면에서 그 다음 y면까지의 광선의 이동거리
	double wall_dist;
	int step_x; //x방향으로 한 칸
	int step_y; //y방향으로 한 칸
	int hit;	//hit은 벽과 부딪혔는지 판별하기 위한 변수.
	int side;
	int line_h;
	int draw_start;
	int draw_end;
	t_texture texture;
	double wallx; //wallx 의 값은 벽의 int형 좌표가 아닌 double형 좌표로 벽의 정확히 어디에 부딪혔는지를 나타냅니다.
	int tex_x;	  //텍스쳐의 x좌표
	int tex_y;	  //텍스터의 y좌표
	unsigned color;
	double step;
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
	int sprite_w;
	int sprite_h;
	int drawstart_x;
	int drawend_x;
	int drawstart_y;
	int drawend_y;
	int d;
	int d_x;
	int d_y;
} t_dda_var;

typedef struct s_map
{
	char **map;
	char **tem;
	int x; //x 좌표
	int y; //y 좌표
	int checkend;
	int user; //유저
	int spr;  //스프라이트
} t_map;
//플레이어의 초기 위치벡터
typedef struct s_pos
{
	double x; //x좌표
	double y; //y좌표
} t_pos;	  //유저 위치
//플레이어의 초기 방향벡터
typedef struct s_dir
{
	double x; //x좌표
	double y; //y좌표
} t_dir;
//플레이어의 카메라 평면
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
//천장과 땅의 컬러 구조체
typedef struct s_color
{
	unsigned int f; //floor
	unsigned int c; //celling
} t_color;
//map.cub 구조체
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
	int all; // 변수 카운트
} t_cub;
//main 종합 구조체
typedef struct s_main
{
	void *mlx;		  //mlx
	void *win;		  //mlx widow
	int w;			  //width
	int h;			  //height
	int save;		  //저장
	int num_sprite;	  //
	int x;			  //x좌표
	int y;			  //y좌표
	int len;		  //길이?
	t_img img;		  //이미지 구조체
	t_texture tex[5]; //선택된 텍스처종류를 나타내는 변수[동 서 남 북 스프라이트]
	t_map map;		  //map 구조체
	t_pos pos;		  //플레이어의 초기 위치 구조체
	t_dir dir;		  //플레이어의 초기 방향벡터 구조체
	t_plane plane;	  //플레이어의 카메라평면 구조체
	t_dda_var v;	  //DDA 알고리즘 구조체
	t_sprite *sp;	  //스프라이트 구조체
	t_color color;	  //천장과 땅의 컬러 구조체
	t_cub cub;		  //map.cub 구조체
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

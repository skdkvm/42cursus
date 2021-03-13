#include "../cub3d.h"

void ft_init_info_tex(t_main *m) //동,서,남,북,스프라이트 초기화
{
	m->tex[0].img = NULL;
	m->tex[1].img = NULL;
	m->tex[2].img = NULL;
	m->tex[3].img = NULL;
	m->tex[4].img = NULL;
}

void ft_init_info_map(t_main *m) //맵 정보 초기화
{
	m->map.map = NULL;
	m->map.tem = NULL;
	m->map.x = 0;
	m->map.y = 0;
	m->map.checkend = 0;
	m->map.user = 0;
	m->map.spr = 0;
}

void ft_init_info_cub(t_main *m) //큐브 정보 초기화
{
	m->cub.i = 0;	//[i]
	m->cub.r = 0;	//해상도
	m->cub.s = 0;	//남
	m->cub.n = 0;	//북
	m->cub.e = 0;	//동
	m->cub.w = 0;	//서
	m->cub.sp = 0;	//스프라이트
	m->cub.f = 0;	//천장
	m->cub.c = 0;	//바닥
	m->cub.map = 0; //맵
	m->cub.all = 0; //구조체 카운트
}

void ft_init_info(t_main *m) //모든 정보 초기화
{
	m->w = 0;			 //width
	m->h = 0;			 //height
	m->save = 0;		 //저장
	ft_init_info_map(m); //맵 정보 초기화
	ft_init_info_tex(m); //텍스 정보 초기화
	m->pos.x = 0;		 //유저 초기 위치 x좌표
	m->pos.y = 0;		 //유저 초기 위치 y좌표
	m->dir.x = 0;		 //유저 초기 방향벡터 x좌표
	m->dir.y = 0;		 //유저 초기 방향벡터 y좌표
	m->plane.x = 0;		 //유저의 카메라 평면 x좌표
	m->plane.y = 0;		 //유저의 카메라 평면 y좌표
	m->sp = NULL;		 //스프라이트
	ft_init_info_cub(m);
}

#include "../cub3d.h"

void ft_put_map_size(t_main *m, char *line)
{
	char **array;

	array = ft_split_line(line); //array = gnl로 읽어온 리턴 값
	if (!(array[1] != 0 && array[2] != 0) || m->cub.r != 0 || array[3] != 0)
	{
		ft_free_array(array);
		ft_put_massage(4); //맵 사이즈가 잘못됨 에러 출력
	}
	m->w = ft_atoi(array[1]); //문자열을 정수로 바꿔서 array배열의[1]에 width에 넣어줌
	m->h = ft_atoi(array[2]); //문자열을 정수로 바꿔서 array배열의[2]에 height에 넣어줌
	if (m->w > 2560 || m->w < 1)
		m->w = 2560;
	if (m->h > 1400 || m->h < 1)
		m->h = 1400;
	m->cub.r = 1;
	++m->cub.all;
	m->win = mlx_new_window(m->mlx, m->w, m->h, "cub3D");
	ft_free_array(array);
}

void ft_put_texture(t_main *m, char *line, int i, int *cub)
{
	char **array;
	int fd;

	array = ft_split_line(line);
	fd = open(array[1], O_RDONLY); //fcntl.h의 내장 함수[파일 제어] 파일을 연다
	if (fd == -1 || (*cub) != 0)
	{
		ft_free_array(array);
		close(fd);
		ft_put_massage(5); //파일의 위치가 잘못됨 에러 출력
	}
	(*cub) = 1;
	++m->cub.all;
	m->tex[i].img =
		mlx_xpm_file_to_image(m->mlx, array[1], &m->tex[i].w, &m->tex[i].h);
	m->tex[i].data = (int *)mlx_get_data_addr(m->tex[i].img,
											  &m->tex[i].bpp, &m->tex[i].len, &m->tex[i].endian);
	ft_free_array(array);
}

void ft_put_background(t_main *m, char *line, int c, int *cub)
{
	int i;
	char **array;

	i = 0;
	array = ft_split_line(line); //R,G,B값
	while (++i < 4)
	{
		if (array[i] == NULL || *cub != 0 ||
			(ft_atoi(array[i]) < 0 || ft_atoi(array[i]) > 255))
		{
			ft_free_array(array);
			ft_put_massage(6); //R, G, B 값이 잘못 입력됨 에러 출력
		}
	}
	(*cub) = 1;
	++m->cub.all;																			   //cub 구조체의 모든 변수 카운트
	if (c == 'C')																			   //Celling 바닥
		m->color.c = (ft_atoi(array[1]) << 16) + (ft_atoi(array[2]) << 8) + ft_atoi(array[3]); //시프트 연산은 변수 << 이동할 비트 수 또는 변수 >> 이동할 비트 수 형식으로 사용합니다.
	if (c == 'F')																			   //Floor 천장
		m->color.f = (ft_atoi(array[1]) << 16) + (ft_atoi(array[2]) << 8) + ft_atoi(array[3]); //즉 지정한 횟수대로 비트를 이동시키며 모자라는 공간은 0으로 채웁니다. 연산자 모양 그대로 <<는 왼쪽, >>는 오른쪽 방향입니다.
	ft_free_array(array);
}

#include "../cub3d.h"
#include <stdio.h>

void ft_check_all_info(t_main *m) //R, NO, SO, WE, EA, S, F, C의 정보
{
	if (m->cub.all != 8 || m->map.map == 0) //cub구조체의 모든 정보가 8개가 들어왔는지 확인 || 맵이 있는지 확인
		ft_put_massage(13);					//충분한 정보가 들어오지 않았다 에러 처리
}

void ft_check_name(char *filename, char *str)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(filename);
	if (len > 4)
	{
		while (++i < 4)
		{
			if (filename[len - 4 + i] != str[i])
				ft_put_massage(1); //잘못된 파일 이름이 들어왔다 에러 처리
		}
	}
	else
		ft_put_massage(1); //잘못된 파일 이름이 들어왔다 에러 처리
}

void ft_check_save(t_main *m, char *save, char *str)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(save);
	if (len == 6)
	{
		while (++i < len)
		{
			if (save[i] != str[i])
				ft_put_massage(2); //저장이 안된다 에러 처리
		}
		m->save = 1;
	}
	else
		ft_put_massage(2); //저장이 안된다 에러 처리
}

void ft_save_info(t_main *m, char *line, int i) //저장된 map.cub정보
{
	if (m->cub.all == 8)
		ft_put_map(m, line, &m->map.x, &m->map.y);
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)) // null, \n, space, 수직tab, 수평tab
		(i)++;
	if (line[i] == 'R' && line[i + 1] == ' ')
		ft_put_map_size(m, line);
	if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		ft_put_texture(m, line, 0, &m->cub.n);
	if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		ft_put_texture(m, line, 1, &m->cub.s);
	if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		ft_put_texture(m, line, 2, &m->cub.w);
	if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		ft_put_texture(m, line, 3, &m->cub.e);
	if (line[i] == 'S' && line[i + 1] == ' ')
		ft_put_texture(m, line, 4, &m->cub.sp);
	if (line[i] == 'F' && line[i + 1] == ' ')
		ft_put_background(m, line, 'F', &m->cub.f);
	if (line[i] == 'C' && line[i + 1] == ' ')
		ft_put_background(m, line, 'C', &m->cub.c);
}

void ft_read_file(t_main *m, int ac, char **av)
{
	char *line;
	int fd;
	int ret;

	ft_check_name(av[1], ".cub"); //map.cub
	if (ac == 3)
		ft_check_save(m, av[2], "--save"); // map.cub --save
	ret = 1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_put_massage(0); //잘못된 값이 들어왔다 에러 처리
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		m->cub.i = 0;
		ft_save_info(m, line, m->cub.i);
		free(line);
	}
	ft_check_all_info(m);
	ft_check_map(m);
	close(fd);
	if (ret == -1)
		ft_put_massage(3);
}

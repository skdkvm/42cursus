#include "../cub3d.h"

void ft_put_massage_two(int num)
{
	if (num == 7)
		ft_putstr("Error\nWall is not '1'\n");
	if (num == 8)
		ft_putstr("Error\nMap size is small\n");
	if (num == 9)
		ft_putstr("Error\nUser num is not one\n");
	if (num == 10)
		ft_putstr("Error\nNo user in map\n");
	if (num == 11)
		ft_putstr("Error\nWrong input value in map\n");
	if (num == 12)
		ft_putstr("Error\nFile already end\n");
	if (num == 13)
		ft_putstr("Error\nNot enough info\n");
	if (num == 14)
		ft_putstr("Error\nMalloc error\n");
	if (num == 15)
		ft_putstr("Error\nbmp file open error\n");
}

void ft_put_massage(int num)
{
	if (num == 0)
		ft_putstr("Error\nInvaild input value\n");
	if (num == 1)
		ft_putstr("Error\nFilename is wrong\n");
	if (num == 2)
		ft_putstr("Error\n\"--save\"\n");
	if (num == 3)
		ft_putstr("Error\nFiled reading file\n");
	if (num == 4)
		ft_putstr("Error\nMap size is wrong\n");
	if (num == 5)
		ft_putstr("Error\nFile path is wrong\n");
	if (num == 6)
		ft_putstr("Error\nColor is wrong\n");
	ft_put_massage_two(num);
	exit(0);
}

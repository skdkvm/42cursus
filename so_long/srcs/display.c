/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:05:26 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:29:15 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_x(t_info *info, int to)
{
	char	*line;

	line = (ft_lst_at(&info->map_ptr, info->player_pos[1]))->content;
	if (line[info->player_pos[0] + to] != '1')
	{
		if (line[info->player_pos[0] + to] == 'C')
			move_collect(info);
		if (line[info->player_pos[0] + to] == 'E')
		{
			if (info->collect != 0)
				return (0);
			ft_putstr_fd("Congratulations ! You won\n", 1);
			quit_game(info);
		}
		line[info->player_pos[0]] = '0';
		line[info->player_pos[0] + to] = 'P';
		info->player_pos[0] += to;
		return (1);
	}
	return (0);
}

int	move_y(t_info *info, int to)
{
	char	*line;
	char	*t_line;

	line = (ft_lst_at(&info->map_ptr, info->player_pos[1]))->content;
	t_line = (ft_lst_at(&info->map_ptr, info->player_pos[1] + to))->content;
	if (t_line[info->player_pos[0]] != '1')
	{
		if (t_line[info->player_pos[0]] == 'C')
			move_collect(info);
		if (t_line[info->player_pos[0]] == 'E')
		{
			if (info->collect != 0)
				return (0);
			ft_putstr_fd("Congratulations! You won!\n", 1);
			quit_game(info);
		}
		line[info->player_pos[0]] = '0';
		t_line[info->player_pos[0]] = 'P';
		info->player_pos[1] += to;
		return (1);
	}
	return (0);
}

void	move_player(t_info *info, int key)
{
	int			check;
	static int	move = 0;

	check = move;
	if (key == 'w' || key == 13)
		move += move_y(info, -1);
	if (key == 'a' || key == 0)
		move += move_x(info, -1);
	if (key == 's' || key == 1)
		move += move_y(info, 1);
	if (key == 'd' || key == 2)
		move += move_x(info, 1);
	if (move != check)
	{
		ft_putstr_fd("Number of moves: ", 1);
		ft_putnbr_fd(move, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	my_key_hook(int key, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (key == 53)
		quit_game((t_info *)param);
	if ((key >= 0 && key < 53) || key == 'w' || key == 'a' || key == 's'
		|| key == 'd')
	{
		move_player((t_info *)param, key);
	}
	mlx_clear_window(info->mlx_ptr, info->window_ptr);
	display_map(info);
	return (0);
}

void	ft_display(t_info *info)
{
	info->window_ptr = mlx_new_window(info->mlx_ptr,
			ft_strlen(info->map_ptr->content) * 64,
			ft_lstsize(info->map_ptr) * 64, "so_long");
	if (!info->window_ptr)
		close_error(NULL, info);
	display_map(info);
	mlx_hook(info->window_ptr, 2, 1L << 0, my_key_hook, info);
	mlx_hook(info->window_ptr, 33, 1L << 17, close_game, info);
	mlx_loop(info->mlx_ptr);
}

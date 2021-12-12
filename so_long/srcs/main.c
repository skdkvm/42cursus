/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:05:57 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:10:36 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit_game(t_info *info)
{
	ft_putstr_fd("Goodbye!\n", 1);
	free_info(info);
	exit(EXIT_SUCCESS);
}

int	close_game(void *info)
{
	quit_game((t_info *)info);
	return (0);
}

void	ft_so_long(char *map)
{
	t_info	*info;

	info = ft_parsing(map);
	load_textures(info);
	ft_display(info);
	free_info(info);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_so_long(av[1]);
	else
		ft_putstr_fd("Error\nusage: ./so_long *.ber\n", 2);
	return (0);
}

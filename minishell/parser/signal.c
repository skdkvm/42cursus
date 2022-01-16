/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:52 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/12 19:04:53 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser/parser.h"

void	ctrl_c(int c)
{
	rl_on_new_line();
	rl_redisplay();
	write(1, "\e[0K\n", 6);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrl_slash(int c)
{
	rl_on_new_line();
	rl_redisplay();
	write(1, "\e[0K", 5);
}

void	ctrl_slash_cat(int c)
{
	write(1, "\e[1KQuit: 3\n", 13);
}

void	ctrl_d(void)
{
	write(1, "\e[1A\e[17C" "exit\n", 15);
}

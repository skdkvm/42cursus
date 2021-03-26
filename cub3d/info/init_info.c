/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:36:36 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/26 16:31:10 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_info_tex(t_main *m)
{
	m->tex[0].img = NULL;
	m->tex[1].img = NULL;
	m->tex[2].img = NULL;
	m->tex[3].img = NULL;
	m->tex[4].img = NULL;
}

void	init_info_map(t_main *m)
{
	m->map.map = NULL;
	m->map.tem = NULL;
	m->map.x = 0;
	m->map.y = 0;
	m->map.checkend = 0;
	m->map.user = 0;
	m->map.spr = 0;
	m->map.spr2 = 0;
}

void	init_info_cub(t_main *m)
{
	m->cub.i = 0;
	m->cub.r = 0;
	m->cub.s = 0;
	m->cub.n = 0;
	m->cub.e = 0;
	m->cub.w = 0;
	m->cub.sp = 0;
	m->cub.sp2 = 0;
	m->cub.f = 0;
	m->cub.c = 0;
	m->cub.map = 0;
	m->cub.all = 0;
}

void	init_info(t_main *m)
{
	m->w = 0;
	m->h = 0;
	m->save = 0;
	init_info_map(m);
	init_info_tex(m);
	m->pos.x = 0;
	m->pos.y = 0;
	m->dir.x = 0;
	m->dir.y = 0;
	m->plane.x = 0;
	m->plane.y = 0;
	m->sp = NULL;
	init_info_cub(m);
}

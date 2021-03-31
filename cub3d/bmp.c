/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:59:33 by seonggki          #+#    #+#             */
/*   Updated: 2021/03/31 16:05:40 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

void		imgbmp(t_main *m, t_bmp *bmp)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		*d;

	j = -1;
	while (++j < m->h)
	{
		i = -1;
		while (++i < m->w)
		{
			x = i;
			y = m->h - 1 - j;
			d = (int *)(m->img.data + (y * m->img.len + x * (m->img.bpp / 8)));
			set_header(bmp->color, *d);
			write(bmp->fd, bmp->color, 4);
		}
	}
}

void		header(t_main *m, t_bmp *bmp)
{
	int		i;

	i = 0;
	while (i < 14)
		bmp->header[i++] = 0;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	set_header(&bmp->header[2], bmp->size);
	bmp->header[10] = 54;
	i = 0;
	while (i < 40)
		bmp->info[i++] = 0;
	bmp->info[0] = 40;
	set_header(&bmp->info[4], m->w);
	set_header(&bmp->info[8], m->h);
	bmp->info[12] = 1;
	bmp->info[14] = 32;
	write(bmp->fd, bmp->header, 14);
	write(bmp->fd, bmp->info, 40);
}

void		bitmap(t_main *m)
{
	t_bmp	bmp;
	int		imgsize;

	main_loop(m);
	imgsize = 4 * m->w * m->h;
	bmp.size = 54 + imgsize;
	bmp.fd = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (bmp.fd == -1)
	{
		free_array(m->map.map);
		free(m->sp);
		error_write(15);
	}
	header(m, &bmp);
	imgbmp(m, &bmp);
	close(bmp.fd);
	free_array(m->map.map);
	free(m->sp);
	exit(0);
}

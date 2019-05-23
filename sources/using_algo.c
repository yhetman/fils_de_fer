/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:37:58 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/23 20:30:05 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline t_algo	init_algo(double x, double y, int decimal)
{
	t_algo	a;

	a.x = x;
	a.y = y;
	a.color = decimal;
	return (a);
}

static void		drawing(t_fdf *f, int i, int j, t_color **p)
{
	draw(f, init_algo(f->x + p[j][i].r, f->y
		+ p[j][i].g, p[j][i].dec),
		init_algo(f->x + p[j][i + 1].r, f->y
		+ p[j][i + 1].g, p[j][i + 1].dec));
}

void			using_algo(t_fdf *f, t_color **p)
{
	t_coord	*i;

	if (!(i = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	i->y = -1;
	while ((i->x = -1) && ++i->y + 1 < f->cor->y)
	{
		while (++i->x + 1 < f->cor->x)
		{
			//a = init_algo(f->x + p[i->y][i->x].r,
			//f->y + p[i->y][i->x].g, p[i->y][i->x].dec);
			drawing(f, i->x, i->y, p);
			//draw(f, init_algo(f->x + p[i->y][i->x].r, f->y + p[i->y][i->x].g, p[i->y][i->x].dec), init_algo(f->x + p[i->y][i->x + 1].r, f->y + p[i->y][i->x + 1].g, p[i->y][i->x + 1].dec));
			draw(f, init_algo(f->x + p[i->y][i->x].r,
			f->y + p[i->y][i->x].g, p[i->y][i->x].dec),
			init_algo(f->x + p[i->y + 1][i->x].r,
			f->y + p[i->y + 1][i->x].g, p[i->y + 1][i->x].dec));
		}
		draw(f, init_algo(f->x + p[i->y][i->x].r,
			f->y + p[i->y][i->x].g, p[i->y][i->x].dec),
			init_algo(f->x + p[i->y + 1][i->x].r,
			f->y + p[i->y + 1][i->x].g, p[i->y + 1][i->x].dec));
	}
		while (++i->x + 1 < f->cor->x)
			drawing(f, i->x, i->y, p);
			//draw(f, init_algo(f->x + p[i->y][i->x].r, f->y + p[i->y][i->x].g, p[i->y][i->x].dec), init_algo(f->x + p[i->y][i->x + 1].r, f->y + p[i->y][i->x + 1].g, p[i->y][i->x + 1].dec));	
}

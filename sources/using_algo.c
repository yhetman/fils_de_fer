/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:37:58 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/13 20:26:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_algo	init_algo(int x, int y, int decimal)
{
	t_algo	a;

	a.dots = (t_coord*)malloc(sizeof(t_coord));
	a.c = (t_coord*)malloc(sizeof(t_coord));
	a.d = (t_coord*)malloc(sizeof(t_coord));
	ft_bzero(a.c, sizeof(t_coord));
	ft_bzero(a.d, sizeof(t_coord));
	ft_bzero(a.dots, sizeof(t_coord));
	a.c->x = x;
	a.c->y = y;
	a.shade = decimal;
	return (a);
}

//static void		drawing(t_fdf *f, int i, int i, t_color **p)
//{
//	draw(f, init_algo(f + p[i][i].r, f
//		+ p[i][i].g, p[j][i].dec),
//		init_algo(f + p[j][i + 1].r, f
//		+ p[j][i + 1].g, p[j][i + 1].dec));
//}

void			using_algo(t_fdf *f, int x, int y, t_color **p)
{
	t_coord	*i;

	if (!(i = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	i->y = -1;
	while ((i->x = -1) && ++i->y + 1 < y)
	{
		while (++i->x + 1 < x)
		{
			draw(f, init_algo(f->x + p[i->y][i->x].r, f->y
			+ p[i->y][i->x].g, p[i->y][i->x].dec),
			init_algo(f->x + p[i->y][i->x + 1].r, f->y
			+ p[i->y][i->x + 1].g, p[i->y][i->x + 1].dec));
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
		while (++i->x + 1 < x)
			draw(f, init_algo(f->x + p[i->y][i->x].r, f->y
			+ p[i->y][i->x].g, p[i->y][i->x].dec),
			init_algo(f->x + p[i->y][i->x + 1].r, f->y
			+ p[i->y][i->x + 1].g, p[i->y][i->x + 1].dec));	
}

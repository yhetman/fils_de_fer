/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 02:39:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/23 19:12:23 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define AB(c)	abs(c)


static float	gradient(int first, int second, float percent)
{
	int		r;
	int		g;
	int		b;

	if (first - second == 0)
		return (first);
	r = (first >> 16) + ((second >> 16)
		- (first >> 16)) * percent;
	g = (first >> 8 & 0xFFFF) + ((second >> 8 & 0xFFFF)
		- (first >> 8 & 0xFFFF)) * percent;
	b = (first & 0xFF) + ((second & 0xFF)
		- (first & 0xFF)) * percent;
	return (r << 16 | g << 8 | b);
}

static float	persentage(int val, int first, int second)
{
	if (val == first)
		return (0.0);
	else if (val == second)
		return (1.0);
	else
		return ((float)(val - first) / (second - first));
}

static void		draw_absis(t_fdf *f, t_algo one, t_algo two, t_line dot)
{
	int i;

	i = 0;
	while (i <= one.d->x)
	{
		if (dot.height >= 0 && dot.color >= 0 &&
			dot.height < WIN_WIDTH && dot.color < WIN_HEIGHT)
			*(int *)(f->image.ptr + dot.color * f->image.size + dot.height
			* f->image.bits) = gradient(one.shade, two.shade,
			persentage(dot.height, one.c->x, two.c->x));
		dot.height += two.c->x >= one.c->x ? 1 : -1;
		if (one.dec > 0)
		{
			one.dec += one.dots->y;
			dot.color += two.c->y >= one.c->y ? 1 : -1;
		}
		else
			one.dec += one.dots->x;
		i++;
	}
}

static void		draw_ordinat(t_fdf *f, t_algo one, t_algo two, t_line dot)
{
	int i;

	i = 0;
	while (i <= one.d->y)
	{
		if (dot.height >= 0 && dot.color >= 0 &&
			dot.height < WIN_WIDTH && dot.color < WIN_HEIGHT)
			*(int *)(f->image.ptr + dot.color * f->image.size + dot.height
			* f->image.bits) = gradient(one.shade, two.shade,
			persentage(dot.height, one.c->y, two.c->y));
		dot.color += two.c->y >= one.c->y ? 1 : -1;
		if (one.dec > 0)
		{
			one.dec += two.dots->y;
			dot.height += two.c->x >= one.c->x ? 1 : -1;
		}
		else
			one.dec += one.dots->x;
		if (dot.height >= 0 && dot.color >= 0 &&
			dot.height < WIN_WIDTH && dot.color < WIN_HEIGHT)
			*(int *)(f->image.ptr + dot.color * f->image.size + dot.height
			* f->image.bits) = gradient(one.shade, two.shade,
			persentage(dot.height, one.c->y, two.c->y));
		i++;
	}
}

void			draw(t_fdf *f, t_algo first, t_algo second)
{
	t_line		coor;

	first.d->x = AB(second.c->x - first.c->x);
	first.d->y = AB(second.c->y - first.c->y);
	coor.height = first.c->x + (second.c->x >= first.c->x ? 1 : -1);
	coor.color = first.c->y;
	if (first.d->y <= first.d->x)
	{
		first.dec = 2 * first.d->y - first.d->x;
		first.dots->x = 2 * first.d->y;
		first.dots->y = 2 * (first.d->y - first.d->x);
		draw_absis(f, first, second, coor);
	}
	else
	{
		first.dec = 2 * first.d->x - first.d->y;
		first.dots->x = 2 * first.d->x;
		first.dots->y = 2 * (first.d->x - first.d->y);
		draw_ordinat(f, first, second, coor);
	}
}

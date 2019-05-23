/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 02:39:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/23 20:23:30 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define AB(c)	abs(c)


static inline double	gradient(int first, int second, double percent)
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

static inline double	persentage(int val, int first, int second)
{
	if (val == first)
		return (0.0);
	else if (val == second)
		return (1.0);
	else
		return ((double)(val - first) / (second - first));
}

static void		draw_absis(t_fdf *f, t_algo one, t_algo two, t_line dot)
{
	int i;

	i = 0;
	while (i++ <= one.dx)
	{
		if (dot.height >= 0 && dot.color >= 0 &&
			dot.height < WIN_WIDTH && dot.color < WIN_HEIGHT)
			*(int *)(f->image.ptr + dot.color * f->image.size + dot.height
			* f->image.bits) = gradient(one.color, two.color,
			persentage(dot.height, one.x, two.x));
		dot.height += two.x >= one.x ? 1 : -1;
		if (one.dec > 0)
		{
			one.dec += one.second;
			dot.color += two.y >= one.y ? 1 : -1;
		}
		else
			one.dec += one.first;
	}
}

static void		draw_ordinat(t_fdf *f, t_algo one, t_algo two, t_line dot)
{
	int i;

	i = 0;
	while (i++ <= one.dy)
	{
		if (dot.height >= 0 && dot.color >= 0
			&& dot.height < WIN_WIDTH && dot.color < WIN_HEIGHT)
			*(int *)(f->image.ptr + dot.color * f->image.size + dot.height *
				f->image.bits) = gradient(one.color, two.color,
					persentage(dot.color, one.y, two.y));
		dot.color += two.y >= one.y ? 1 : -1;
		if (one.dec > 0)
		{
			one.dec += one.second;
			dot.height += two.x >= one.x ? 1 : -1;
		}
		else
			one.dec += one.first;
		if (dot.height >= 0 && dot.color >= 0 &&
				dot.height < WIN_WIDTH && dot.color < WIN_HEIGHT)
			*(int *)(f->image.ptr + dot.color * f->image.size + dot.height *
				f->image.bits) = gradient(one.color, two.color,
					persentage(dot.color, one.y, two.y));
	}
}

void			draw(t_fdf *f, t_algo first, t_algo second)
{
	t_line		coor;

	first.dx = AB(second.x - first.x);
	first.dy = AB(second.y - first.y);
	coor.height = first.x + (second.x >= first.x ? 1 : -1);
	coor.color = first.y;
	if (first.dy <= first.dx)
	{
		first.dec = 2 * first.dy - first.dx;
		first.first = 2 * first.dy;
		first.second = 2 * (first.dy - first.dx);
		draw_absis(f, first, second, coor);
	}
	else
	{
		first.dec = 2 * first.dx - first.dy;
		first.first = 2 * first.dx;
		first.second = 2 * (first.dx - first.dy);
		draw_ordinat(f, first, second, coor);
	}
}

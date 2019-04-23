/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 02:39:28 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/23 18:33:33 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


static void		draw_absis(t_fdf *f, t_algo one, t_algo two,
					t_line dot)
{
	int i;

	i = 0;
	while (i++ <= one.d->x)
	{
		if (dot.height >= 0 && dot.color >= 0 &&
			dot.height < WIDTH && dot.color < WIN_HEIGHT)
			*(int *)(f->image.ptr + dot.color * f->image.size + dot.height
			* f->image.bpp) = gradient(one.shade, two.shade,
			persentage(dot.height, one.c->x, two.c->x));
		dot.height += two.c->x >= one.c->x ? 1 : -1;
		if (one.dec > 0)
		{
			one.dec += one.dots->y;
			dot.color += two.c->y >= one.c->y ? 1 : -1;
		}
		else
			one.dec += one.dots->x;
	}
}

void			draw(t_fdf *f, t_algo first, t_algo second)
{
	t_line		coor;

	first.d->x = ABS(second.c->x - first.c->x);
	first.d->y = ABS(second.c->y - first.c->y);
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
		f->check = 10;
		//draw_ordinat(f, first, second, coor);
	}
	return ;
}
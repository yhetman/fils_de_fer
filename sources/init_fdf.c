/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:24:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 15:32:16 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_coord(t_fdf *fdf)
{
	t_coord	*c;

	if (!(c = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	c->y = -1;
	fdf->points = (t_color **)malloc(sizeof(t_color *) * fdf->y);
	while ((c->x = -1) && ++c->y < fdf->y)
	{
		fdf->points[c->y] = (t_color *)malloc(sizeof(t_color) * fdf->x);
		while (++c->x < fdf->x)
		{
			fdf->points[c->y][c->x] =
				rotation(fdf, fdf->zoom * (c->x - fdf->x / 2),
				fdf->zoom * (c->y - fdf->y / 2),
				fdf->zoom * fdf->height * fdf->l[c->y][c->x].height);
			fdf->points[c->y][c->x].r += WIN_WIDTH / 2;
			fdf->points[c->y][c->x].g += WIN_HEIGHT / 2;
			if (fdf->l[c->y][c->x].color)
				fdf->points[c->y][c->x].dec = fdf->l[c->y][c->x].color;
			else if (fdf->l[c->y][c->x].height != 0)
				fdf->points[c->y][c->x].dec = 0xFF0000;
			else
				fdf->points[c->y][c->x].dec = 0xFF00;
		}
	}
}

t_fdf		*init_fdf(t_line **l, t_coord *c)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		mal_error();
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	init_image(fdf->mlx, &fdf->image);
	fdf->l = l;
	fdf->x = c->x;
	fdf->y = c->y;
	ft_bzero(fdf->coord, sizeof(t_coord));
	if (c->y >= c->x)
		fdf->zoom = WIN_HEIGHT / fdf->y;
	else
		fdf->zoom = WIN_WIDTH / fdf->x;
	fdf->height = 0.1;
	fdf->info = 1;
	fdf->rot.x = 0;
	fdf->rot.y = 0;
	fdf->rot.z = 0;
	init_coord(fdf);
	return (fdf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:24:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/03 17:54:53 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_points(t_fdf *fdf)
{
	t_coord	*c;

	if (!(c = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	c->y = -1; 
	fdf->points = (t_color **)malloc(sizeof(t_color *) * fdf->cor->y);
	while ((c->x = -1) && ++c->y < fdf->cor->y)
	{
		fdf->points[c->y] = (t_color *)malloc(sizeof(t_color) * fdf->cor->x);
		while (++c->x < fdf->cor->x)
		{
			fdf->points[c->y][c->x] = 
				counting_rotation(fdf, fdf->z * (c->x - fdf->cor->x / 2),
				fdf->z * (c->y - fdf->cor->y / 2),
				fdf->z * fdf->h * fdf->line[c->y][c->x].height);
			fdf->points[c->y][c->x].r += WIN_WIDTH / 2;
			fdf->points[c->y][c->x].g += WIN_HEIGHT / 2;
			if (fdf->line[c->y][c->x].color)
				fdf->points[c->y][c->x].dec = fdf->line[c->y][c->x].color;
			else if (fdf->line[c->y][c->x].height != 0)
				fdf->points[c->y][c->x].dec = 0xFF0000;
			else
				fdf->points[c->y][c->x].dec = 0xFF00;
		}
	}
}

t_fdf		*init_fdf(t_line **line, t_coord *c)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		mal_error();
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fils_de_fer");
	init_image(fdf->mlx, &fdf->image);
	ft_bzero(fdf->cor, sizeof(t_coord));
	fdf->line = line;
	fdf->x = c->x;
	fdf->y = c->y;
	fdf->h = 0.1;
	fdf->info = 1;
	fdf->rot.x = 0;
	fdf->rot.y = 0;
	fdf->rot.z = 0;
	if (c->y >= c->x)
		fdf->z = WIN_HEIGHT / fdf->y;
	else
		fdf->z = WIN_WIDTH / fdf->x;
	init_points(fdf);
	return (fdf);
}

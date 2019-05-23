/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:24:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/23 20:13:57 by yhetman          ###   ########.fr       */
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
			fdf->points[c->y][c->x] = counting_rotation(fdf,
				fdf->z * (c->x - fdf->cor->x / 2),
				fdf->z * (c->y - fdf->cor->y / 2),
				fdf->z * fdf->h * fdf->line[c->y][c->x].height / 2);
			fdf->points[c->y][c->x].r += WIN_WIDTH / 2;
			fdf->points[c->y][c->x].g += WIN_HEIGHT / 2;
			if (fdf->line[c->y][c->x].color)
				fdf->points[c->y][c->x].dec = fdf->line[c->y][c->x].color;
			else if (fdf->line[c->y][c->x].height != 0)
				fdf->points[c->y][c->x].dec = 0xFFFFFF;
			else
				fdf->points[c->y][c->x].dec = 0xFFFF;
		}
	}
}

t_fdf		*init_fdf(t_line **line, t_coord *c)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		mal_error();
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->cor = (t_coord *)malloc(sizeof(t_coord));
	ft_bzero(fdf->cor, sizeof(t_coord));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fils_de_fer");
	init_image(fdf->mlx, &fdf->image);
	fdf->line = line;
	fdf->cor->x = c->x;
	fdf->cor->y = c->y;
	fdf->h = 0.1;
	fdf->info = 1;
	ft_bzero(&(fdf->rot), sizeof(t_rot));
	fdf->x = 0;
	fdf->y = 0;
	if (c->y >= c->x)
		fdf->z = WIN_HEIGHT / fdf->cor->y / 2;
	else
		fdf->z = WIN_WIDTH / fdf->cor->x / 2;
	init_points(fdf);
	return (fdf);
}

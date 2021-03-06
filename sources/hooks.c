/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:16:09 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/25 23:24:21 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			reset_points(t_fdf *fdf)
{
	t_coord	*c;

	c = (t_coord*)malloc(sizeof(t_coord));
	c->y = -1;
	while ((c->x = -1) && ++c->y < fdf->cor->y)
	{
		while (++c->x < fdf->cor->x)
		{
			fdf->points[c->y][c->x] = counting_rotation(fdf,
			fdf->z * (c->x - fdf->cor->x / 2),
			fdf->z * (c->y - fdf->cor->y / 2),
			fdf->z * fdf->h * fdf->line[c->y][c->x].height / 2);
			fdf->points[c->y][c->x].r += WIN_WIDTH / 2;
			fdf->points[c->y][c->x].g += WIN_HEIGHT / 2;
			if (fdf->line[c->y][c->x].color)
				fdf->points[c->y][c->x].dec =
				fdf->line[c->y][c->x].color;
			else if (fdf->line[c->y][c->x].height != 0)
				fdf->points[c->y][c->x].dec = 0xFFFFFF;
			else
				fdf->points[c->y][c->x].dec = 0xFFFF;
		}
	}
	ft_memdel((void**)&c);
}

static inline void	creating(t_fdf *fdf)
{
	if (fdf->z < 0)
		fdf->z = 0;
	reset_points(fdf);
	using_algo(fdf, fdf->points);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.image, 0, 0);
	display_menu(fdf, fdf->name);
}

int					exit_hook(void)
{
	system("leaks fdf");
	exit(EXIT_SUCCESS);
	return (0);
}

int					define_hook(int c, t_fdf *fdf)
{
	if (c == 53)
		exit_hook();
	if (c == 13 || c == 0 || c == 1
		|| c == 2 || c == 43 || c == 47)
		rotation(c, fdf);
	if (c == 126 || c == 123
		|| c == 124 || c == 125)
		movement(c, fdf);
	if (c == 69 || c == 78)
		change_height(c, fdf);
	if (c == 6 || c == 7)
		zoom(c, fdf);
	if (c == 51)
		refreshing(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_bzero((void *)fdf->image.ptr, WIN_WIDTH * WIN_HEIGHT * 4);
	creating(fdf);
	return (0);
}

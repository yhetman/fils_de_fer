/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:16:09 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 19:51:39 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_points(t_fdf *fdf)
{
	t_coord	*c;

	if (!(c = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	c->y = -1;
	while ((c->x = -1) && ++c->y < fdf->y)
	{
		while (++c->x < fdf->x)
		{
			fdf->points[c->y][c->x] = counting_rotations(fdf, fdf->zoom * (c->x - fdf->x / 2),
			fdf->zoom * (c->y - fdf->y / 2),
			fdf->zoom * fdf->height * fdf->line[c->y][c->x].height);
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

void	creating(t_fdf *fdf)
{
	if (fdf->zoom < 0)
		fdf->zoom = 0;
	reset_points(fdf);
}

void	deleting(t_fdf *fdf)
{
	if (fdf->y < fdf->x)
		fdf->zoom = WIN_WIDTH / fdf->x;
	else
		fdf->zoom = WIN_HEIGHT / fdf->y;
	fdf->height = 0.1;
	ft_bzero(&(fdf->rot), sizeof(t_rot));
	fdf->x = 0;
	fdf->y = 0;
}

void	rotation(int c, t_fdf *fdf)
{
	if (c == 13)
		fdf->rot.x += 0.05 * M_PI;
	else if (c == 1)
		fdf->rot.x -= 0.05 * M_PI;
	else if (c == 0)
		fdf->rot.y -= 0.05 * M_PI;
	else if (c == 2)
		fdf->rot.y += 0.05 * M_PI;
	else if (c == 43)
		fdf->rot.z -= 0.05 * M_PI;
	else if (c == 47)
		fdf->rot.z += 0.05 * M_PI;
}
void	movement(int c, t_fdf *fdf)
{
	if (c == 124)
		fdf->y -= 10;
	else if (c == 123)
		fdf->x -= 10;
	else if (c == 124)
		fdf->x += 10;
	else if (c == 125)
		fdf->y += 10;
}
void	zoom(int c, t_fdf *fdf)
{
	if (c == 7)
		fdf->zoom += 0.1;
	else if (c == 6)
		fdf->zoom -= 0.1;
}
void	change_height(int c, t_fdf *fdf)
{
	if (c == 69 )
		fdf->height += 0.01;
	else if (c == 78)
		fdf->height -= 0.01;
}

int	define_hook(int c, t_fdf *fdf)
{
	if (c == 53)
		exit_hook(53, fdf);
	if (c == 13 ||c == 0
		|| c == 1 || c == 2 || c == 43 || c == 47)
		rotation(c, fdf);
	else if (c == 126|| c == 123 ||
		c == 124 || c == 125)
		movement(c, fdf);
	else if (c == 69 || c == 78)
		change_height(c, fdf);
	else if (c == 6 || c == 7)
		zoom(c, fdf);
	else if (c == 51)
		deleting(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_bzero((void *)fdf->image.ptr, WIN_WIDTH * WIN_HEIGHT * 4);
	creating(fdf);
	return (0);
}

int	exit_hook(int c, void *param)
{
	t_fdf	*f;

	f = (t_fdf*)param;
	if (c == EXIT_CODE)
		exit(EXIT_SUCCESS);
	return (0);
}

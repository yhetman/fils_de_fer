/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:18:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/18 03:43:48 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	refreshing(t_fdf *fdf)
{
	if (fdf->y < fdf->x)
		fdf->z = WIN_WIDTH / fdf->x;
	else
		fdf->z = WIN_HEIGHT / fdf->y;
	fdf->h = 0.1;
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
	if (c == 126)
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
		fdf->z += 0.1;
	else if (c == 6)
		fdf->z -= 0.1;
}

void	change_height(int c, t_fdf *fdf)
{
	if (c == 69 )
		fdf->h += 0.01;
	else if (c == 78)
		fdf->h -= 0.01;
}

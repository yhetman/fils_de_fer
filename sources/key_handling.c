/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:18:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/13 19:26:29 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	refreshing(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	if (fdf->cor->y >= fdf->cor->x)
		fdf->z = WIN_HEIGHT / fdf->cor->y / 2;
	else
		fdf->z = WIN_WIDTH / fdf->cor->x / 2;
	fdf->h = 0.01;
	ft_bzero(&(fdf->rot), sizeof(t_rot));
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
		fdf->y -= 20;
	else if (c == 123)
		fdf->x -= 20;
	else if (c == 124)
		fdf->x += 20;
	else if (c == 125)
		fdf->y += 20;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:36:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 15:36:44 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color		rotation(t_fdf *fdf, float x, float y, float z)
{
	t_color	point;

	point.r = x * (cos(fdf->rot.y) * cos(fdf->rot.z))
			- y * (sin(fdf->rot.z) * cos(fdf->rot.y))
			+ z * (sin(fdf->rot.y));
	point.g = x * (sin(fdf->rot.x) * sin(fdf->rot.y)
			* cos(fdf->rot.z) + cos(fdf->rot.x) * sin(fdf->rot.z))
			+ y * (-sin(fdf->rot.x) * sin(fdf->rot.y)
			* sin(fdf->rot.z) + cos(fdf->rot.x) * cos(fdf->rot.z))
			- z * (sin(fdf->rot.x) * cos(fdf->rot.y));
	point.b = x * (-cos(fdf->rot.x) * sin(fdf->rot.y)
			* cos(fdf->rot.z) - sin(fdf->rot.x) * sin(fdf->rot.z))
			+ y * (cos(fdf->rot.x) * sin(fdf->rot.y)
			* sin(fdf->rot.z) + sin(fdf->rot.x) * cos(fdf->rot.z))
			+ z * cos(fdf->rot.x) * cos(fdf->rot.y);
	return (point);
}

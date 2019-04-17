/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:37:21 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 18:42:20 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define st_rot		fdf->rot

t_color		counting_rotation(t_fdf *fdf, double x, double y, double z)
{	
	t_color	point;

	point.r = x * (COS(st_rot.y) * COS(st_rot.z))
			- y * (SIN(st_rot.z) * COS(st_rot.y))
			+ z * (SIN(st_rot.y));
	point.g = x * (SIN(st_rot.x) * SIN(st_rot.y)
			* COS(st_rot.z) + COS(st_rot.x) * SIN(st_rot.z))
			+ y * (-SIN(st_rot.x) * SIN(st_rot.y)
			* SIN(st_rot.z) + COS(st_rot.x) * COS(st_rot.z))
			- z * (SIN(st_rot.x) * COS(st_rot.y));
	point.b = x * (-COS(st_rot.x) * SIN(st_rot.y)
			* COS(st_rot.z) - SIN(st_rot.x) * SIN(st_rot.z))
			+ y * (COS(st_rot.x) * SIN(st_rot.y)
			* SIN(st_rot.z) + SIN(st_rot.x) * COS(st_rot.z))
			+ z * COS(st_rot.x) * COS(st_rot.y);
	return (point);
}

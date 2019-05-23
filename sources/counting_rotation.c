/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:37:21 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/23 20:17:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color		counting_rotation(t_fdf *f, double x, double y, double z)
{	
	t_color	point;

	point.r = x * (COS(f->rot.y) * COS(f->rot.z)) - y
				* (SIN(f->rot.z) * COS(f->rot.y)) + z * (SIN(f->rot.y));
	point.g = x * (SIN(f->rot.x) * SIN(f->rot.y) * COS(f->rot.z)
				+ COS(f->rot.x) * SIN(f->rot.z)) + y * (-SIN(f->rot.x)
				* SIN(f->rot.y) * SIN(f->rot.z) + COS(f->rot.x)
				* COS(f->rot.z)) - z * (SIN(f->rot.x) * COS(f->rot.y));
	point.b = x * (-COS(f->rot.x) * SIN(f->rot.y) * COS(f->rot.z)
				- SIN(f->rot.x) * SIN(f->rot.z)) + y * (COS(f->rot.x)
				* SIN(f->rot.y) * SIN(f->rot.z) + SIN(f->rot.x)
				* COS(f->rot.z)) + z * COS(f->rot.x) * COS(f->rot.y);
	return (point);
}

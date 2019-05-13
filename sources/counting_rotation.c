/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:37:21 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/13 19:57:55 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color		counting_rotation(t_rot rot, double x, double y, double z)
{	
	t_color	point;

	point.r = x * (COS(rot.y) * COS(rot.z)) - y
				* (SIN(rot.z) * COS(rot.y)) + z * (SIN(rot.y));
	point.g = x * (SIN(rot.x) * SIN(rot.y) * COS(rot.z)
				+ COS(rot.x) * SIN(rot.z)) + y * (-SIN(rot.x)
				* SIN(rot.y) * SIN(rot.z) + COS(rot.x)
				* COS(rot.z)) - z * (SIN(rot.x) * COS(rot.y));
	point.b = x * (-COS(rot.x) * SIN(rot.y) * COS(rot.z)
				- SIN(rot.x) * SIN(rot.z)) + y * (COS(rot.x)
				* SIN(rot.y) * SIN(rot.z) + SIN(rot.x)
				* COS(rot.z)) + z * COS(rot.x) * COS(rot.y);
	return (point);
}

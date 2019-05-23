/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:19:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/23 14:19:26 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
#include "fdf.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_rotation
{
	float			x;
	float			y;
	float			z;
}					t_rot;

typedef struct		s_line
{
	int				height;
	int				color;
}			 		t_line;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bits;
	int				size;
	int				end;
}					t_image;

typedef struct		s_algo
{
	t_coord			*dots; //x = dot1, y = dot2;
	t_coord			*c;
	t_coord			*d;
	int				shade;
	int				dec;
}					t_algo;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_image			image;
	t_line			**line;
	t_color			**points;
	t_coord			*cor;
	//t_palette		*palette;
	t_rot			rot;
	char			*name;
	float			x;
	float			y;
	float			z;
	float			h;
	int				info;
}					t_fdf;

/*
typedef struct		s_palette
{
	t_color			*c_1;
	t_color			*c_2;
	t_color			*c_3;
	t_color			*c_4;
	t_color			*c_5;
}					t_palette;
*/

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:19:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/25 23:35:29 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "fdf.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_line
{
	int				height;
	int				color;
}					t_line;

typedef struct		s_rotation
{
	double			x;
	double			y;
	double			z;
}					t_rot;

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
	int				x;
	int				y;
	int				color;
	int				dx;
	int				dy;
	int				dec;
	int				first;
	int				second;
}					t_algo;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_image			image;
	t_line			**line;
	t_color			**points;
	t_coord			*cor;
	t_rot			rot;
	char			*name;
	double			x;
	double			y;
	double			z;
	double			h;
}					t_fdf;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:31:52 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/06 19:40:33 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include "mlx.h"
#include "structs.h"

# define WIN_HEIGHT 1000
# define WIN_WIDTH  1000

void	mlx_error(void);
int		map_error(void);
void	mal_error(void);
int		arg_error(void);
int		file_error(void);

void	display_menu(t_fdf *fdf, char *name);
void	init_image(void *mlx, t_image *image);

void	draw(t_fdf *f, t_algo first, t_algo second);

void	using_algo(t_fdf *f, int x, int y, t_color **p);

void	rotation(int keycode, t_fdf *fdf);
void	movement(int keycode, t_fdf *fdf);
void	change_height(int keycode, t_fdf *fdf);
void	zoom(int keycode, t_fdf *fdf);
void	refreshing(t_fdf *fdf);

int		exit_hook(int keycode, void *ptr);
int		define_hook(int keycode, t_fdf *fdf);

int		is_valid(t_fdf **fdf, char *str);

t_line	**init_line(t_coord *c, char *map, char *line);

t_fdf	*init_fdf(t_line **l, t_coord *c);

t_color	counting_rotation(t_rot rot, double x,
		double y, double z);
#endif

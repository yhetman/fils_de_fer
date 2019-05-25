/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:31:52 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/25 23:36:28 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include "structs.h"

# define WIN_HEIGHT	1000
# define WIN_WIDTH	1000

/*
**		error.c
*/
void	mlx_error(void);
int		map_error(void);
void	mal_error(void);
int		arg_error(void);
int		file_error(void);

/*
**		free.c
*/
void	free_line(t_line **line);

/*
**		main.c
*/
void	display_menu(t_fdf *fdf, char *name);
void	init_image(void *mlx, t_image *image);

/*
**		draw.c
*/
void	draw(t_fdf *f, t_algo first, t_algo second);

/*
**		using_algo.c
*/
void	using_algo(t_fdf *f, t_color **p);

/*
**		key_handling.c
*/
void	rotation(int keycode, t_fdf *fdf);
void	movement(int keycode, t_fdf *fdf);
void	change_height(int keycode, t_fdf *fdf);
void	zoom(int keycode, t_fdf *fdf);
void	refreshing(t_fdf *fdf);

/*
**		hooks.c
*/
int		define_hook(int keycode, t_fdf *fdf);
int		exit_hook(void);
int		is_valid(t_fdf **fdf, char *str);

/*
**		init_line.c
*/
t_line	**init_line(t_coord *c, char *map, char *line);

/*
**		init_fdf.c
*/
t_fdf	*init_fdf(t_line **l, t_coord *c);

/*
**		counting_rotation.c
*/
t_color	counting_rotation(t_fdf *f, double x,
		double y, double z);

#endif

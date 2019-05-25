/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:01:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/26 00:11:08 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				init_image(void *mlx, t_image *image)
{
	image->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	image->ptr = mlx_get_data_addr(image->image, &(image->bits),
		&(image->size), &(image->end));
	image->bits /= 8;
}

void				display_menu(t_fdf *fdf, char *name)
{
	mlx_string_put(fdf->mlx, fdf->win, 400, 10, 0x6495ED,
		"Fils_de_Fer");
	mlx_string_put(fdf->mlx, fdf->win, 80, 40, 0x6495ED,
		"MENU OF CONTROLLERS");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0x87CEEB, "MAP: ");
	mlx_string_put(fdf->mlx, fdf->win, 60, 60, 0x87CEEB, name);
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0x87CEEB,
			"TO ROTATE USE: 'W' 'A' 'S' 'D' '<' '>' ");
	mlx_string_put(fdf->mlx, fdf->win, 10, 120, 0x87CEEB,
			"TO ZOOM USE: 'Z' and 'X' ");
	mlx_string_put(fdf->mlx, fdf->win, 10, 150, 0x87CEEB,
			"TO CHANGE HEIGHT USE: '+' and '-' ");
	mlx_string_put(fdf->mlx, fdf->win, 10, 180, 0x87CEEB,
			"TO MOVE USE ARROWS");
	mlx_string_put(fdf->mlx, fdf->win, 10, 210, 0x87CEEB,
			"TO EXIT PRESS 'ESC'");
	mlx_string_put(fdf->mlx, fdf->win, 10, WIN_HEIGHT - 25, 0xB0E0E6,
			"AUTHOR: Yuliia HETMAN");
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.ptr, 0, 0);
}

static inline void	mlx_manager(t_fdf *fdf, char *name)
{
	init_image(fdf->mlx, &fdf->image);
	fdf->name = ft_strdup(name);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.image, 0, 0);
	display_menu(fdf, fdf->name);
}

int					main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (arg_error());
	if (is_valid(&fdf, argv[1]))
		return (1);
	mlx_manager(fdf, argv[1]);
	mlx_hook(fdf->win, 17, 0, exit_hook, fdf);
	mlx_hook(fdf->win, 2, 0, define_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

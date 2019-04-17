/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:01:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 17:17:01 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_image		*init_image(void *mlx, t_image *image)
{
	image->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	image->ptr = mlx_get_data_addr(image->image, &(image->bpp),
		&(image->size), &(image->end));
	image->bpp /= 8;
	return (image);
}

static void	display_menu(t_fdf *fdf, char *name)
{
	t_image	*image;
	int		width;

	width = 300;
	image = NULL;
	image = init_image(mlx_new_image(fdf->mlx, width, WIN_HEIGHT),
			image);
	mlx_put_image_to_window(fdf->mlx, fdf->win, image->ptr, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 80, 10, 0xFFFFFF, "Fils_de_Fer Controls");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0xFFFFFF, "MAP:");
	mlx_string_put(fdf->mlx, fdf->win, 60, 60, 0xFFFFFF, name);
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF,
			"TO ROTATE USE: ^ v < >");
	mlx_string_put(fdf->mlx, fdf->win, 10, 120, 0xFFFFFF,
			"TO ZOOM: MOUSE UP or MOUSE DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 10, 150, 0xFFFFFF,
			"TO CHANGE HEIGHT: + or -");
	mlx_string_put(fdf->mlx, fdf->win, 10, 180, 0xFFFFFF, "TO EXIT: ESC");
	mlx_string_put(fdf->mlx, fdf->win, 10, WIN_HEIGHT - 25, 0xFFFFFF,
			"AUTHOR: Yuliia HETMAN");
	ft_memdel((void*)&image);
}

static void	mlx_manager(t_fdf *fdf, char *name)
{
	init_image(fdf->mlx, &fdf->image);
	display_menu(fdf, name);
	mlx_key_hook(fdf->win, exit_hook, fdf);
	//mlx_hook(win, 2, 0, define_keycode, fdf);
	//mlx_mouse_hook(win, zoom_hook, fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*name;

	name = argv[1];
	if (argc != 2)
		arg_error();
	if (is_valid(&fdf, argv[1]))
		return (1);
	//ft_music(); system("afplay -v &");
	mlx_manager(fdf, name);
	mlx_loop(fdf->mlx);
	return (0);
}

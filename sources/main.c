/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:01:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/04 14:07:27 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_image	*init_image(void *image, int color, int width, int height)
{
	t_image	*s_image;
    int		i;

    i = -1;
	if (!(s_image = (t_image*)ft_memalloc(sizeof(t_image))))
		mal_error();
	s_image->ptr = image;
	s_image->data = (int *)mlx_get_data_addr(s_image->ptr, &s_image->b,
			&s_image->size, &s_image->end);
    while (++i < height * width)
		s_image->data[i] = color;
	return (s_image);
}

static void		display_menu(t_fdf *fdf)
{
	t_image	*image;
	int		width;

	width = 300;
	image = init_image(mlx_new_image(fdf->mlx, width, WIN_HEIGHT),
			0x262626, width, WIN_HEIGHT);
	mlx_put_image_to_window(fdf->mlx, fdf->win, image->ptr, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 80, 10, 0xFFFFFF, "FDF Controls");
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0xFFFFFF, "MAP:");
	mlx_string_put(fdf->mlx, fdf->win, 60, 60, 0xFFFFFF, fdf->line);
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF,
			"TO ROTATE USE: ^ v < >");
	mlx_string_put(fdf->mlx, fdf->win, 10, 120, 0xFFFFFF,
			"TO ZOOM: MOUSE UP or MOUSE DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 10, 150, 0xFFFFFF,
			"TO CHANGE HEIGHT: + or -");
	mlx_string_put(fdf->mlx, fdf->win, 10, 180, 0xFFFFFF, "TO EXIT: ESC");
	mlx_string_put(fdf->mlx, fdf->win, 10, WIN_HEIGHT - 25, 0xFFFFFF,
			"AUTHOR: YHETMAN");
	ft_memdel((void*)&image);
}

static	void mlx_manager(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	**split;

	if (!(mlx = mlx_init()))
		exit(EXIT_FAILURE);
	split = ft_strsplit(fdf->line, '/');
	while (*split)
		split++;
	split--;
	if (!(win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, *split)))
		exit(EXIT_FAILURE);
	fdf->mlx = mlx;
	fdf->win = win;
	display_menu(fdf);
	mlx_key_hook(win, exit_hook, fdf);
	//mlx_hook(win, 2, 0, define_keycode, fdf);
	//mlx_mouse_hook(win, zoom_hook, fdf);
    mlx_loop(fdf->mlx);
}

int 		main(int argc, char **argv)
{
    t_fdf	fdf;

	if (argc != 2)
		arg_error();
	fdf.line = argv[1];
	if (validation(&fdf))
		return (1);
	//system("afplay -v &");
	mlx_manager(&fdf);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:01:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/29 21:06:06 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			save_ordinat(char *str)
{
	int		ordinat;
	int		res;
	int		fd;
	char	*line;

	ordinat = -1;
	fd = open(str, O_RDONLY);
	while ((++ordinat > -1 && (res = get_next_line(fd, &line))) > 0 )
		ft_strdel(&line);
	if (res < 0)
		return (-1);
	close(fd);
	return (ordinat);
}

static int			save_absis(char *str)
{
	int		absis;
	int		tmp;
	int		i;
	int		fd;
	char	*line;

	absis = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) && (tmp = 0) && (i = -1))
	{
		while (line[++i])
			if (line[i] != ' ' && (line[i + 1] == ' ' || !line[i + 1]))
				tmp++;
		ft_strdel(&line);
		if (!absis && absis != tmp)
			absis = tmp;
		else if (absis != tmp || !absis)
			return (-1);
	}
	close(fd);
	return (absis);
}

static int	validation(t_fdf *fdf)
{
	t_coord	*c;

	c = (t_coord*)malloc(sizeof(t_coord));
	if ((c->x = save_absis(fdf->line)) <= 0)
		return (ft_strerr("ERROR: Invalid map."));
	if ((c->y = save_ordinat(fdf->line)) < 0)
		return (ft_strerr("ERROR: Invalid name of file."));
	*fdf = init_fdf(init_line(fdf, c), c);
	return (0);
}

static t_image	*init_image(void *image, int color, int width, int height)
{
	t_image	*s_image;
    int		i;

    i = -1;
	//if (!(s_image = (t_image*)ft_memalloc(sizeof(t_image))))
	//	mal_error();
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
	//mlx_mouse_hook(win, zoom_hook, f)df;
    mlx_loop(fdf->mlx);
}

void		mal_error(void)
{
	ft_strerr("ERROR:\t Malloc failed.\n");
	exit(EXIT_FAILURE);
}

void		arg_error(void)
{
	ft_strerr("ERROR:\t Wrong number of arguments.\nUSAGE:\t ./fdf <map_filename>");
	exit(EXIT_FAILURE);
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
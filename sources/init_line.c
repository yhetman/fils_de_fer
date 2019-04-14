/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:24:11 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/14 21:31:30 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		coloring(char *line, int *color)
{
	int hexa;

	hexa = 0;
	while (IS_PRINT(line[hexa]) || IS_DIGIT(line[hexa]))
		hexa++;
	if (line[hexa++] != ' ')
	{
		if (line[hexa] == '0' && line[hexa + 1] == 'x')
		{
			*color = ft_htoi(line + hexa + 2);
			hexa += 2;
		}
		else
			*color = ft_atoi(line + hexa);
	}
}

static t_line	**fill_the_line(char ***str, t_coord *c, t_line **l)
{
	t_coord *in;

	if (!(in = (t_coord *)malloc(sizeof(t_coord))))
		mal_error();
	in->y = -1;
	while (++in->y < c->y)
	{
		l[in->y] = (t_line *)malloc(sizeof(t_line) * c->x);
		in->x = -1;
		while (++in->x < c->x)
		{
			l[in->y][in->x].height = ft_atoi(str[in->y][in->x]);
			coloring(str[in->y][in->x], &l[in->y][in->x].color);
		}
	}
	return (l);
}

t_line			**init_line(t_fdf *fdf, t_coord *c, char *line)
{

	int			i;
	int			fd;
	t_line		**l;
	char		***grid;

	i = 0;
	if (!(grid = (char ***)malloc(sizeof(char **) * (c->y + 1))))
		 mal_error();
	grid[c->y] = 0;
	fd = open(fdf->line, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		grid[i++] = ft_strsplit(line, ' ');
		ft_strdel(&line);
	}
	close(fd);
	if (!(l = (t_line **)malloc(sizeof(t_line *) * c->y)))
		 mal_error();
	l = fill_the_line(grid, c, l);
	ft_free_grid(grid);
	return (l);
}
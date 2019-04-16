/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:24:11 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 00:14:51 by yhetman          ###   ########.fr       */
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

static t_line	**fill_the_line(char ***str, t_coord *c, t_line **line)
{
	t_coord *in;

	if (!(in = (t_coord *)malloc(sizeof(t_coord))))
		mal_error();
	in->y = -1;
	while (++in->y < c->y)
	{
		line[in->y] = (t_line *)malloc(sizeof(t_line) * c->x);
		in->x = -1;
		while (++in->x < c->x)
		{
			line[in->y][in->x].height = ft_atoi(str[in->y][in->x]);
			coloring(str[in->y][in->x], &line[in->y][in->x].color);
		}
	}
	return (line);
}

t_line			**init_line(t_fdf *fdf, t_coord *c, char *map)
{
	int			i;
	int			fd;
	char		*str;
	t_line		**line;
	char		***grid;

	i = 0;
	str = NULL;
	if (!(grid = (char ***)malloc(sizeof(char **) * (c->y + 1))))
		 mal_error();
	grid[c->y] = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		grid[i++] = ft_strsplit(str, ' ');
		ft_strdel(&str);
	}
	close(fd);
	if (!(line = (t_line **)malloc(sizeof(t_line *) * c->y)))
		 mal_error();
	line = fill_the_line(grid, c, line);
	ft_free_grid(grid);
	return (line);
}
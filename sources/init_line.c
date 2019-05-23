/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:24:11 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/23 16:27:50 by yhetman          ###   ########.fr       */
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

t_line			**init_line(t_coord *c, char *map, char *row)
{
	int			i;
	int			fd;
	t_line		**line;
	char		***grid;

	i = 0;
	if (!(grid = (char ***)malloc(sizeof(char **) * (c->y + 1))))
		return (0);
	grid[c->y] = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &row))
	{
		grid[i++] = ft_strsplit(row, ' ');
		ft_strdel(&row);
	}
	close(fd);
	if (!(line = (t_line **)malloc(sizeof(t_line *) * c->y)))
		return (0);
	fill_the_line(grid, c, line);
	ft_free_grid(grid);
	return (line);
}

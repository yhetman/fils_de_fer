/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:28:10 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 17:03:18 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	save_ordinat(char *str)
{
	int		ordinat;
	int		res;
	int		fd;
	char	*line;

	ordinat = -1;
	fd = open(str, O_RDONLY);
	while ((++ordinat > -1 && (res = get_next_line(fd, &line))) > 0)
		ft_strdel(&line);
	if (res < 0)
		return (-1);
	close(fd);
	return (ordinat);
}

static int	save_absis(char *str)
{
	int		absis;
	int		tmp;
	int		i;
	int		fd;
	char	*line;

	absis = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = -1;
		tmp = 0;
		while (line[++i])
			if (line[i] != ' ' && (line[i + 1] == ' ' || !line[i + 1]))
				tmp++;
		ft_strdel(&line);
		if (absis != tmp && !absis)
			absis = tmp;
		else if (absis != tmp || !absis)
			return (-1);
	}
	close(fd);
	return (absis);
}

int			is_valid(t_fdf **fdf, char *map)
{
	t_coord	*c;

	if (!(c = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	ft_bzero(c, sizeof(t_coord));
	if ((c->x = save_absis(map)) <= 0)
		map_error();
	if ((c->y = save_ordinat(map)) < 0)
		file_error();
	*fdf = init_fdf(init_line(c, map), c);
	return (0);
}

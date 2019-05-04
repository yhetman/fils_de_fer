/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:28:10 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/04 20:42:48 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	save_ordinat(char *map)
{
	int		fd;
	int		res;
	int		ordinat;
	char	*line;

	ordinat = 0;
	fd = open(map, O_RDONLY);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		ordinat++;
		ft_strdel(&line);
	}
	if (res < 0)
		return (-1);
	close(fd);
	return (ordinat);
}

static int	save_absis(char *map)
{
	int		i;
	int		fd;
	int		tmp;
	int		absis;
	char	*line;

	absis = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = -1;
		tmp = 0;
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

int			is_valid(t_fdf **fdf, char *map)
{
	t_coord	*c;
	char	*line;

	line = NULL;
	if (!(c = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	//ft_bzero(c, sizeof(t_coord));
	if ((c->y = save_ordinat(map)) < 0)
		file_error();
	if ((c->x = save_absis(map)) <= 0)
		map_error();
	*fdf = init_fdf(init_line(c, map, line), c);
	return (0);
}

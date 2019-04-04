/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:28:10 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/04 16:36:00 by yhetman          ###   ########.fr       */
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

int	validation(t_fdf *fdf)
{
	t_coord	*c;
	char 	*line;

	if (!(c = (t_coord*)malloc(sizeof(t_coord))))
		mal_error();
	if ((c->y = save_ordinat(fdf->line)) < 0)
		return (ft_strerr("Error: Invalid name of file."));
	if ((c->x = save_absis(fdf->line)) <= 0)
		return (ft_strerr("Error: Invalid map."));
	line = NULL;
	fdf = init_fdf(init_line(fdf, c, line), c);
	return (0);
}
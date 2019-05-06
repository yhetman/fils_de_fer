/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:06:45 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/06 19:40:18 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mal_error(void)
{
	ft_printf("ERROR:\t Malloc failed. %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

int		file_error(void)
{
	ft_printf("%{red}Error: Invalid name of file.%{eoc}\n");
	return (1);
}

int		map_error(void)
{
	ft_printf("%{red}Error: Invalid map.%{eoc}\n");
	return (1);
}

void	mlx_error(void)
{
	ft_printf("%{red}Error: troubles with creating window.%{eoc}\n");
	exit(EXIT_FAILURE);
}

int		arg_error(void)
{
	ft_printf("%{red}ERROR:\t Wrong number of arguments.\n");
	ft_printf("%{blue}USAGE:\t ./fdf <map_filename>%{eoc}\n");
	return (1);
}

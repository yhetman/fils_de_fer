/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:06:45 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 15:34:19 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mal_error(void)
{
	ft_printf("ERROR:\t Malloc failed. %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_printf("ERROR:\t Wrong number of arguments.\n");
	ft_printf("USAGE:\t ./fdf <map_filename>\n");
	exit(EXIT_FAILURE);
}

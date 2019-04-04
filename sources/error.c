/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:06:45 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/04 14:08:57 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

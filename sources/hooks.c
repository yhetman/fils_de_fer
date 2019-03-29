/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:16:09 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/29 11:24:48 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     exit_hook(int keycode, void *param)
{
	t_fdf	*f;

	f = (t_fdf*)param;
	if (keycode == EXIT_CODE)
		exit(EXIT_SUCCESS);
	return (0);
}
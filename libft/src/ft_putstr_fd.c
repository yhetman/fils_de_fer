/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:28:31 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/29 11:19:44 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int j;

	j = -1;
	if (!s)
		return (0);
	while (s[++j] != '\0')
		ft_putchar_fd(s[j], fd);
	return (j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:03:36 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/29 10:53:29 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	integer(char h)
{
	if (h < 'a' || h > 'f')
		if (h < 'A' || h > 'F')
			if (h < '0' || h > '9')
				return (0);
	if (h >= 'a' && h <= 'f')
		h = ft_toupper(h);
	if (h >= 'A' && h <= 'F')
		return (h - 'A' + 10);
	return (h - '0');
}

int			ft_htoi(char *hexa)
{
	int		i;
	int		j;
	int		power;
	int		result;

	result = 0;
	power = 1;
	if (!hexa || (i = ft_strlen(hexa) - 1) == 0)
		return (0);
	j = -1;
	if (hexa[++j] == '0')
		if (hexa[j] == 'x' || hexa[j] == 'X')
			j++;
	while (i >= j)
	{
		result += integer(hexa[i]) * power;
		power *= 16;
		i--;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:39:03 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:39:04 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**fdf_put_in_map(int **map, char *str)
{
	int		n;
	int		s;
	int		i;

	n = 0;
	s = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			map[n][s++] = ft_atoi(&str[i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i++] == '\n')
		{
			n++;
			s = 0;
		}
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
			i++;
	}
	return (map);
}

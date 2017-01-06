/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:49 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:50 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**fdf_make_map(int n, int s, char *str)
{
	int		i;
	int		**map;

	if (!(map = (int **)malloc(sizeof(int *) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * s)))
			return (NULL);
		i++;
	}
	map = fdf_put_in_map(map, str);
	return (map);
}

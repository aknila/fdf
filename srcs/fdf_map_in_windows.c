/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_in_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:57 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:58 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_map_in_windows(t_ptr *ptr)
{
	int i;
	int j;
	t_map *m;

	m = ptr->map;
	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			if (j + 1 < m->c)
				fdf_aff_horizontale(i, j, m, ptr);
			if (i + 1 < m->l)
				fdf_aff_verticale(i, j, m, ptr);
			j++;
		}
		i++;
	}
}

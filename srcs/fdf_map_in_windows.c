/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_in_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:57 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:22:07 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_map_in_windows(t_ptr *ptr)
{
	int		i;
	int		j;
	t_map	*m;

	m = ptr->map;
	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			fdf_aff_conv_point(ptr, m, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->ptr_img, 0, 0);
}

void	fdf_aff_conv_point(t_ptr *ptr, t_map *m, int i, int j)
{
	int i2;
	int j2;

	i2 = fdf_conv_x(i - (ptr->map->l / 2),
		j - (ptr->map->c / 2), m->map[i][j], ptr);
	j2 = fdf_conv_y(i - (ptr->map->l / 2),
		j - (ptr->map->c / 2), m->map[i][j], ptr);
	if (ptr->v1 == 0)
		mlx_pix_img(ptr, i2, j2, fdf_colo(m->map[i][j], ptr));
	if (j + 1 < m->c)
		fdf_aff_horizontale(i, j, m, ptr);
	if (i + 1 < m->l)
		fdf_aff_verticale(i, j, m, ptr);
	if (ptr->d == 1)
	{
		if (i + 1 < m->l && j + 1 < m->c)
			fdf_aff_diag_1(i, j, m, ptr);
		if (i > 0 && j + 1 < m->c)
			fdf_aff_diag_2(i, j, m, ptr);
	}
}

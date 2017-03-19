/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_in_windows2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:59:05 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:22:37 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_colo(int nbr, t_ptr *ptr)
{
	if (ptr->c == 0)
		return (fdf_col(nbr));
	if (ptr->c == 1)
		return (fdf_col(1) - 20 * nbr);
	if (ptr->c == 2)
		return (fdf_col(2) - 20 * nbr);
	if (ptr->c == 3)
		return (fdf_col(3) - 20 * nbr);
	if (ptr->c == 4)
		return (fdf_col(4) - 20 * nbr);
	if (ptr->c == 5)
		return (fdf_col(5) - 20 * nbr);
	if (ptr->c == 6)
		return (fdf_col(6) - 20 * nbr);
	if (ptr->c == 7)
		return (fdf_col(7) - 20 * nbr);
	if (ptr->c == 8)
		return (fdf_col(8) - 20 * nbr);
	if (ptr->c == 9)
		return (fdf_col(9) - 20 * nbr);
	if (ptr->c == 10)
		return (fdf_col(10) - 20 * nbr);
	return (0);
}

int		fdf_col(int m)
{
	while (m < 0)
		m += 11;
	if (m % 11 == 0)
		return (0x00ffffff);
	if (m % 11 == 1)
		return (0x00bcbcbc);
	if (m % 11 == 2)
		return (0x00996600);
	if (m % 11 == 3)
		return (0x00ff9933);
	if (m % 11 == 4)
		return (0x00ffaf00);
	if (m % 11 == 5)
		return (0x0000cc00);
	if (m % 11 == 6)
		return (0x0033ffff);
	if (m % 11 == 7)
		return (0x000099ff);
	if (m % 11 == 8)
		return (0x000033ff);
	if (m % 11 == 9)
		return (0x009900cc);
	if (m % 11 == 10)
		return (0x00cc0000);
	return (0);
}

void	fdf_map_in_windows2(t_ptr *ptr)
{
	int		i;
	int		j;
	int		sx;
	int		sy;
	t_map	*m;

	m = ptr->map;
	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			sy = j * (2 * ptr->sz + 1) + ptr->sz + ptr->y;
			sx = i * (2 * ptr->sz + 1) + ptr->sz + ptr->x;
			mlx_aff_point(sy, sx, ptr, fdf_colo(m->map[i][j], ptr));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->ptr_img, 0, 0);
}

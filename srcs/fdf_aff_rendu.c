/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aff_rendu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:37:48 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:37:50 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_aff_horizontale(int i, int j, t_map *m, t_ptr *ptr)
{
	// int h;
	// int a;
	// int xa;
	// int bx;
	// int ya;
	// int by;

	// xa = 0;
	// ya = 0;
	// h = ptr->h;
	// bx = ptr->sz + ptr->y;
	// by = ptr->sz + ptr->x;
	// a = (2 * ptr->sz + 1);
	// ptr->x0 = (j * cos(ptr->t2) * cos(ptr->t3) + i * -sin(ptr->t3) * cos(ptr->t2) + (h * m->map[i][j]) * sin(ptr->t2) + xa) * a + bx;
	// ptr->x1 = ((j + 1) * cos(ptr->t2) * cos(ptr->t3) + i * -sin(ptr->t3) * cos(ptr->t2) + (h * m->map[i][j + 1]) * sin(ptr->t2) + xa) * a + bx;
	// ptr->y0 = (j * (cos(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + sin(ptr->t3) * cos(ptr->t1)) + i * ( -sin(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + cos(ptr->t3) * cos(ptr->t1)) + (h * m->map[i][j]) * -sin(ptr->t1) * cos(ptr->t2) + ya) * a + by;
	// ptr->y1 = ((j + 1) * (cos(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + sin(ptr->t3) * cos(ptr->t1)) + i * ( -sin(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + cos(ptr->t3) * cos(ptr->t1)) + (h * m->map[i][j + 1]) * -sin(ptr->t1) * cos(ptr->t2) + ya) * a + by;
	ptr->x0 = fdf_conv_x(i, j, m->map[i][j], ptr);
	ptr->x1 = fdf_conv_x(i, j + 1, m->map[i][j + 1], ptr);
	ptr->y0 = fdf_conv_y(i, j, m->map[i][j], ptr);
	ptr->y1 = fdf_conv_y(i, j + 1, m->map[i][j + 1], ptr);
	ptr->colors = 0x00bcbcbc;
	if (m->map[i][j] != 0 || m->map[i][j + 1] != 0)
	{
		ptr->colors = 0x0033cc00;
		ptr->colors += ABS(m->map[i][j] - m->map[i][j + 1]) * 0x000000FF;
	}
	mlx_put_line(ptr);
}

void	fdf_aff_verticale(int i, int j, t_map *m, t_ptr *ptr)
{
	// int h;
	// int a;
	// int xa;
	// int bx;
	// int ya;
	// int by;

	// xa = 0;
	// ya = 0;
	// h = ptr->h;
	// bx = ptr->sz + ptr->y;
	// by = ptr->sz + ptr->x;
	// a = (2 * ptr->sz + 1);
	// ptr->x0 = (j * cos(ptr->t2) * cos(ptr->t3) + i * -sin(ptr->t3) * cos(ptr->t2) + (h * m->map[i][j]) * sin(ptr->t2) + xa) * a + bx;
	// ptr->x1 = (j * cos(ptr->t2) * cos(ptr->t3) + (i + 1) * -sin(ptr->t3) * cos(ptr->t2) + (h * m->map[i + 1][j]) * sin(ptr->t2) + xa) * a + bx;
	// ptr->y0 = (j * (cos(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + sin(ptr->t3) * cos(ptr->t1)) + i * ( -sin(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + cos(ptr->t3) * cos(ptr->t1)) + (h * m->map[i][j]) * -sin(ptr->t1) * cos(ptr->t2) + ya) * a + by;
	// ptr->y1 = (j * (cos(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + sin(ptr->t3) * cos(ptr->t1)) + (i + 1) * ( -sin(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + cos(ptr->t3) * cos(ptr->t1)) + (h * m->map[i + 1][j]) * -sin(ptr->t1) * cos(ptr->t2) + ya) * a + by;
	ptr->x0 = fdf_conv_x(i, j, m->map[i][j], ptr);
	ptr->x1 = fdf_conv_x(i + 1, j, m->map[i + 1][j], ptr);
	ptr->y0 = fdf_conv_y(i, j, m->map[i][j], ptr);
	ptr->y1 = fdf_conv_y(i + 1, j, m->map[i + 1][j], ptr);
	ptr->colors = 0x00bcbcbc;
	if (m->map[i][j] != 0 || m->map[i + 1][j] != 0)
	{
		ptr->colors = 0x0033cc00;
		ptr->colors += ABS(m->map[i][j] - m->map[i + 1][j]) * 0x000000FF;
	}
	mlx_put_line(ptr);
}

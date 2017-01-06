/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:24:11 by aancel            #+#    #+#             */
/*   Updated: 2016/12/20 19:24:16 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_map_in_windows(t_ptr *ptr)
{
	int i;
	int j;
	int a;
	int h;
	int xa;
	int ya;
	int bx;
	int by;
	double t1;
	double t2;
	double t3;
	t_map *m;

	t1 = ptr->t1;
	t2 = ptr->t2;
	t3 = ptr->t3;
	h = ptr->h;
	bx = ptr->sz + ptr->y;
	by = ptr->sz + ptr->x;
	m = ptr->map;
	xa = 0;
	ya = 0;
	a = (2 * ptr->sz + 1);

	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			if (j + 1 < m->c)
			{
				ptr->x0 = (j * cos(t2) * cos(t3) + i * -sin(t3) * cos(t2) + (h * m->map[i][j]) * sin(t2) + xa) * a + bx;
				ptr->x1 = ((j + 1) * cos(t2) * cos(t3) + i * -sin(t3) * cos(t2) + (h * m->map[i][j + 1]) * sin(t2) + xa) * a + bx;
				ptr->y0 = (j * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + i * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (h * m->map[i][j]) * -sin(t1) * cos(t2) + ya) * a + by;
				ptr->y1 = ((j + 1) * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + i * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (h * m->map[i][j + 1]) * -sin(t1) * cos(t2) + ya) * a + by;
				ptr->colors = 0x00bcbcbc;
				if (m->map[i][j] != 0 || m->map[i][j + 1] != 0)
					ptr->colors = 0x0033cc00 + ABS(m->map[i][j] - m->map[i][j + 1]) * 0x000000FF;
				mlx_put_line(ptr);
			}
			if (i + 1 < m->l)
			{
				ptr->x0 = (j * cos(t2) * cos(t3) + i * -sin(t3) * cos(t2) + (h * m->map[i][j]) * sin(t2) + xa) * a + bx;
				ptr->x1 = (j * cos(t2) * cos(t3) + (i + 1) * -sin(t3) * cos(t2) + (h * m->map[i + 1][j]) * sin(t2) + xa) * a + bx;
				ptr->y0 = (j * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + i * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (h * m->map[i][j]) * -sin(t1) * cos(t2) + ya) * a + by;
				ptr->y1 = (j * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + (i + 1) * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (h * m->map[i + 1][j]) * -sin(t1) * cos(t2) + ya) * a + by;
				ptr->colors = 0x00bcbcbc;
				if (m->map[i][j] != 0 || m->map[i + 1][j] != 0)
					ptr->colors = 0x0033cc00 + ABS(m->map[i][j] - m->map[i + 1][j]) * 0x000000FF;
				mlx_put_line(ptr);
			}
			j++;
		}
		i++;
	}


	// i = 0;
	// while (i < m->l)
	// {
	// 	j = 0;
	// 	while (j < m->c)
	// 	{
	// 		if (j + 1 < m->c)
	// 		{
	// 			ptr->x0 = (cos(t3) * j - sin(t3) * i + xa) * a + bx;
	// 			ptr->x1 = (cos(t3) * (j + 1) - sin(t3) * i + xa) * a + bx;
	// 			ptr->y0 = (sin(t3) * j + cos(t3) * i - m->map[i][j] + ya) * a + by;
	// 			ptr->y1 = (sin(t3) * (j + 1) + cos(t3) * i - m->map[i][j + 1] + ya) * a + by;
	// 			ptr->colors = 0x00bcbcbc;
	// 			if (m->map[i][j] != 0 || m->map[i][j + 1] != 0)
	// 				ptr->colors = 0x00ffaf00;
	// 			mlx_put_line(ptr);
	// 		}
	// 		if (i + 1 < m->l)
	// 		{
	// 			ptr->x0 = (cos(t3) * j - sin(t3) * i + xa) * a + bx;
	// 			ptr->x1 = (cos(t3) * j - sin(t3) * (i + 1) + xa) * a + bx;
	// 			ptr->y0 = (sin(t3) * j + cos(t3) * i - m->map[i][j] + ya) * a + by;
	// 			ptr->y1 = (sin(t3) * j + cos(t3) * (i + 1) - m->map[i + 1][j] + ya) * a + by;
	// 			ptr->colors = 0x00bcbcbc;
	// 			if (m->map[i][j] != 0 || m->map[i + 1][j] != 0)
	// 				ptr->colors = 0x00ffaf00;
	// 			mlx_put_line(ptr);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }



	// i = 0;
	// while (i < m->l)
	// {
	// 	j = 0;
	// 	while (j < m->c)
	// 	{
	// 		if (j + 1 < m->c)
	// 		{
	// 			ptr->x0 = (j - i + xa) * a + ptr->sz + ptr->y;
	// 			ptr->x1 = ((j + 1) - i + xa) * a + ptr->sz + ptr->y;
	// 			ptr->y0 = (j + i + m->map[i][j] * b) * a + ptr->sz + ptr->x;
	// 			ptr->y1 = ((j + 1) + i + m->map[i][j + 1] * b) * a + ptr->sz + ptr->x;
	// 			ptr->colors = 0x00bcbcbc;
	// 			// if (m->map[i][j] == 1 || m->map[i][j + 1] == 1)
	// 				// ptr->colors = 0x00ffaf00;
	// 			mlx_put_line(ptr);
	// 		}
	// 		if (i + 1 < m->l)
	// 		{
	// 			ptr->x0 = (j - i + xa) * a + ptr->sz + ptr->y;
	// 			ptr->x1 = (j - (i + 1) + xa) * a + ptr->sz + ptr->y;
	// 			ptr->y0 = (j + i + m->map[i][j] * b) * a + ptr->sz + ptr->x;
	// 			ptr->y1 = (j + (i + 1) + m->map[i + 1][j] * b) * a + ptr->sz + ptr->x;
	// 			ptr->colors = 0x00bcbcbc;
	// 			// if (m->map[i][j] == 1 || m->map[i + 1][j] == 1)
	// 				// ptr->colors = 0x00ffaf00;
	// 			mlx_put_line(ptr);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
}
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
	int x;
	int y;

	x = ptr->map->l / 2;
	y = ptr->map->c / 2;
	ptr->x0 = fdf_conv_x(i - x, j - y, m->map[i][j], ptr);
	ptr->x1 = fdf_conv_x(i - x, j + 1 - y, m->map[i][j + 1], ptr);
	ptr->y0 = fdf_conv_y(i - x, j - y, m->map[i][j], ptr);
	ptr->y1 = fdf_conv_y(i - x, j + 1 - y, m->map[i][j + 1], ptr);
	ptr->colors = 0x00bcbcbc;
	// if (m->map[i][j] != 0 || m->map[i][j + 1] != 0)
	// {
	// 	ptr->colors = 0x0033cc00;
	// 	ptr->colors += ABS(m->map[i][j] - m->map[i][j + 1]) * 0x000000FF;
	// }
	ptr->colors = (m->map[i][j] > m->map[i][j + 1] ? fdf_colo(m->map[i][j], ptr) : fdf_colo(m->map[i][j + 1], ptr));
	if (ptr->v1 == 1 && (m->map[i][j] <= ptr->v || m->map[i][j + 1] <= ptr->v))
		return ;
	if ((ptr->x0 < 0 && ptr->x1 < 0) || (ptr->x0 > SIZE_X && ptr->x1 > SIZE_X) || (ptr->y0 < 0 && ptr->y1 < 0) || (ptr->y0 > SIZE_Y && ptr->y1 > SIZE_Y))
		return ;
	mlx_put_line(ptr);
}

void	fdf_aff_verticale(int i, int j, t_map *m, t_ptr *ptr)
{
	int x;
	int y;

	x = ptr->map->l / 2;
	y = ptr->map->c / 2;
	ptr->x0 = fdf_conv_x(i - x, j - y, m->map[i][j], ptr);
	ptr->x1 = fdf_conv_x(i + 1 - x, j - y, m->map[i + 1][j], ptr);
	ptr->y0 = fdf_conv_y(i - x, j - y, m->map[i][j], ptr);
	ptr->y1 = fdf_conv_y(i + 1 - x, j - y, m->map[i + 1][j], ptr);
	ptr->colors = 0x00bcbcbc;
	// if (m->map[i][j] != 0 || m->map[i + 1][j] != 0)
	// {
	// 	ptr->colors = 0x0033cc00;
	// 	ptr->colors += ABS(m->map[i][j] - m->map[i + 1][j]) * 0x000000FF;
	// }
	ptr->colors = (m->map[i][j] > m->map[i + 1][j] ? fdf_colo(m->map[i][j], ptr) : fdf_colo(m->map[i + 1][j], ptr));
	if (ptr->v1 == 1 && (m->map[i][j] <= ptr->v || m->map[i + 1][j] <= ptr->v))
		return ;
	if ((ptr->x0 < 0 && ptr->x1 < 0) || (ptr->x0 > SIZE_X && ptr->x1 > SIZE_X) || (ptr->y0 < 0 && ptr->y1 < 0) || (ptr->y0 > SIZE_Y && ptr->y1 > SIZE_Y))
		return ;
	mlx_put_line(ptr);
}

void	fdf_aff_diag_1(int i, int j, t_map *m, t_ptr *ptr)
{
	int x;
	int y;

	x = ptr->map->l / 2;
	y = ptr->map->c / 2;
	ptr->x0 = fdf_conv_x(i - x, j - y, m->map[i][j], ptr);
	ptr->x1 = fdf_conv_x(i + 1 - x, j + 1 - y, m->map[i + 1][j + 1], ptr);
	ptr->y0 = fdf_conv_y(i - x, j - y, m->map[i][j], ptr);
	ptr->y1 = fdf_conv_y(i + 1 - x, j + 1 - y, m->map[i + 1][j + 1], ptr);
	ptr->colors = 0x00bcbcbc;
	// if (m->map[i][j] != 0 || m->map[i + 1][j] != 0)
	// {
	// 	ptr->colors = 0x0033cc00;
	// 	ptr->colors += ABS(m->map[i][j] - m->map[i + 1][j]) * 0x000000FF;
	// }
	ptr->colors = (m->map[i][j] > m->map[i + 1][j + 1] ? fdf_colo(m->map[i][j], ptr) : fdf_colo(m->map[i + 1][j + 1], ptr));
	if (ptr->v1 == 1 && (m->map[i][j] <= ptr->v || m->map[i + 1][j + 1] <= ptr->v))
		return ;
	if ((ptr->x0 < 0 && ptr->x1 < 0) || (ptr->x0 > SIZE_X && ptr->x1 > SIZE_X) || (ptr->y0 < 0 && ptr->y1 < 0) || (ptr->y0 > SIZE_Y && ptr->y1 > SIZE_Y))
		return ;
	mlx_put_line(ptr);
}

void	fdf_aff_diag_2(int i, int j, t_map *m, t_ptr *ptr)
{
	int x;
	int y;

	x = ptr->map->l / 2;
	y = ptr->map->c / 2;
	ptr->x0 = fdf_conv_x(i - x, j - y, m->map[i][j], ptr);
	ptr->x1 = fdf_conv_x(i - 1 - x, j + 1 - y, m->map[i - 1][j + 1], ptr);
	ptr->y0 = fdf_conv_y(i - x, j - y, m->map[i][j], ptr);
	ptr->y1 = fdf_conv_y(i - 1 - x, j + 1 - y, m->map[i - 1][j + 1], ptr);
	ptr->colors = 0x00bcbcbc;
	// if (m->map[i][j] != 0 || m->map[i + 1][j] != 0)
	// {
	// 	ptr->colors = 0x0033cc00;
	// 	ptr->colors += ABS(m->map[i][j] - m->map[i + 1][j]) * 0x000000FF;
	// }
	ptr->colors = (m->map[i][j] > m->map[i - 1][j + 1] ? fdf_colo(m->map[i][j], ptr) : fdf_colo(m->map[i - 1][j + 1], ptr));
	if (ptr->v1 == 1 && (m->map[i][j] <= ptr->v || m->map[i - 1][j + 1] <= ptr->v))
		return ;
	if ((ptr->x0 < 0 && ptr->x1 < 0) || (ptr->x0 > SIZE_X && ptr->x1 > SIZE_X) || (ptr->y0 < 0 && ptr->y1 < 0) || (ptr->y0 > SIZE_Y && ptr->y1 > SIZE_Y))
		return ;
	mlx_put_line(ptr);
}

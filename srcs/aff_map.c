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

int		key_code(int keycode, t_ptr *ptr)
{
	if (keycode == 82)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->b--;
	}
	if (keycode == 65)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->b++;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	if (keycode == 83)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t1 += PI / 36;
	}
	if (keycode == 86)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t1 = 0;
	}
	if (keycode == 89)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t1 -= PI / 36;
	}
	if (keycode == 84)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t2 += PI / 36;
	}
	if (keycode == 87)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t2 = 0;
	}
	if (keycode == 91)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t2 -= PI / 36;
	}
	if (keycode == 85)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t3 += PI / 36;
	}
	if (keycode == 88)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t3 = 0;
	}
	if (keycode == 92)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->t3 -= PI / 36;
	}
	if (keycode == 71)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
	}
	if (keycode == 69)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->size += 1;
		if (ptr->size > ptr->size_x / 6)
			ptr->size -= 1;
	}
	if (keycode == 78)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->size -= 1;
		if (ptr->size < 0)
			ptr->size = 0;
	}
	if (keycode == 126)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->x = ptr->x - (2 * ptr->size + 1);
	}
	if (keycode == 125)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->x = ptr->x + (2 * ptr->size + 1);
	}
	if (keycode == 124)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->y = ptr->y + (2 * ptr->size + 1);
	}
	if (keycode == 123)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->y = ptr->y - (2 * ptr->size + 1);
	}
	if (keycode == 36)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		ptr->form++;
		if (ptr->form > 1)
			ptr->form = 0;
	}
	if (ptr->x < 0 + ptr->size)
		ptr->x = 0;
	if (ptr->x > ptr->size_x - ptr->size)
		ptr->x = ptr->size_x;
	if (ptr->y < 0 + ptr->size)
		ptr->y = 0;
	if (ptr->y > ptr->size_y - ptr->size)
		ptr->y = ptr->size_y;
	if (ptr->form == 0)
	{
		fdf_map_in_windows(ptr);
	}
	if (ptr->form == 1)
	{
		fdf_map_in_windows2(ptr);
	}
	return (0);
}

int 	aff_point(int x, int y, t_ptr *ptr, int color)
{
	int a;
	int b;
	int size;

	size = ptr->size;
	a = x - size;
	while (a <= x + size)
	{
		b = y - size;
		while (b <= y + size)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, a, b, color);
			b++;
		}
		a++;
	}
	return (0);
}

void	fdf_aff_map(int l, int c, int **tab)
{
	t_map m;
	t_ptr ptr;

	m.l = l;
	m.c = c;
	m.map = tab;
	ptr.map = &m;
	ptr.size_x = 1000;
	ptr.size_y = 1000;
	ptr.size = 1;
	ptr.x = c / 2;
	ptr.y = l / 2;
	ptr.t1 = 0;
	ptr.t2 = 0;
	ptr.t3 = 0;
	ptr.b = 0;
	ptr.form = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.size_x, ptr.size_y, "Affichage");
	fdf_map_in_windows(&ptr);
	mlx_hook(ptr.win, 2, 3, key_code, &ptr);
	mlx_loop(ptr.mlx);
}

void	fdf_map_in_windows(t_ptr *ptr)
{
	int i;
	int j;
	int a;
	int b;
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
	b = ptr->b;
	bx = ptr->size + ptr->y;
	by = ptr->size + ptr->x;
	m = ptr->map;
	xa = 0;
	ya = 0;
	a = (2 * ptr->size + 1);

	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			if (j + 1 < m->c)
			{
				ptr->x0 = (j * cos(t2) * cos(t3) + i * -sin(t3) * cos(t2) + (b * m->map[i][j]) * sin(t2) + xa) * a + bx;
				ptr->x1 = ((j + 1) * cos(t2) * cos(t3) + i * -sin(t3) * cos(t2) + (b * m->map[i][j + 1]:) * sin(t2) + xa) * a + bx;
				ptr->y0 = (j * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + i * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (b * m->map[i][j]) * -sin(t1) * cos(t2) + ya) * a + by;
				ptr->y1 = ((j + 1) * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + i * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (b * m->map[i][j + 1]) * -sin(t1) * cos(t2) + ya) * a + by;
				ptr->colors = 0x00bcbcbc;
				if (m->map[i][j] != 0 || m->map[i][j + 1] != 0)
					ptr->colors = 0x0033cc00 + ABS(m->map[i][j] - m->map[i][j + 1]) * 0x000000FF;
				mlx_put_line(ptr);
			}
			if (i + 1 < m->l)
			{
				ptr->x0 = (j * cos(t2) * cos(t3) + i * -sin(t3) * cos(t2) + (b * m->map[i][j]) * sin(t2) + xa) * a + bx;
				ptr->x1 = (j * cos(t2) * cos(t3) + (i + 1) * -sin(t3) * cos(t2) + (b * m->map[i + 1][j]) * sin(t2) + xa) * a + bx;
				ptr->y0 = (j * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + i * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (b * m->map[i][j]) * -sin(t1) * cos(t2) + ya) * a + by;
				ptr->y1 = (j * (cos(t3) * -sin(t1) * -sin(t2) + sin(t3) * cos(t1)) + (i + 1) * ( -sin(t3) * -sin(t1) * -sin(t2) + cos(t3) * cos(t1)) + (b * m->map[i + 1][j]) * -sin(t1) * cos(t2) + ya) * a + by;
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
	// 			ptr->x0 = (j - i + xa) * a + ptr->size + ptr->y;
	// 			ptr->x1 = ((j + 1) - i + xa) * a + ptr->size + ptr->y;
	// 			ptr->y0 = (j + i + m->map[i][j] * b) * a + ptr->size + ptr->x;
	// 			ptr->y1 = ((j + 1) + i + m->map[i][j + 1] * b) * a + ptr->size + ptr->x;
	// 			ptr->colors = 0x00bcbcbc;
	// 			// if (m->map[i][j] == 1 || m->map[i][j + 1] == 1)
	// 				// ptr->colors = 0x00ffaf00;
	// 			mlx_put_line(ptr);
	// 		}
	// 		if (i + 1 < m->l)
	// 		{
	// 			ptr->x0 = (j - i + xa) * a + ptr->size + ptr->y;
	// 			ptr->x1 = (j - (i + 1) + xa) * a + ptr->size + ptr->y;
	// 			ptr->y0 = (j + i + m->map[i][j] * b) * a + ptr->size + ptr->x;
	// 			ptr->y1 = (j + (i + 1) + m->map[i + 1][j] * b) * a + ptr->size + ptr->x;
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

void	fdf_map_in_windows2(t_ptr *ptr)
{
	int i;
	int j;
	int a;
	t_map *m;

	m = ptr->map;
	a = (2 * ptr->size + 1);
	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			if (m->map[i][j] == 0)
				aff_point(j * a + ptr->size + ptr->y, i * a + ptr->size + ptr->x, ptr, 0x00000000);  // NOIR
			if (m->map[i][j] == 1)
				aff_point(j * a + ptr->size + ptr->y, i * a + ptr->size + ptr->x, ptr, 0x00ffaf00);  // JAUNE
			if (m->map[i][j] == 2)
				aff_point(j * a + ptr->size + ptr->y, i * a + ptr->size + ptr->x, ptr, 0x00FFFFFF);  // BLANC
			if (m->map[i][j] == 10)
				aff_point(j * a + ptr->size + ptr->y, i * a + ptr->size + ptr->x, ptr, 0x00FFFFFF);  // BLANC
			if (m->map[i][j] == 3)
				aff_point(j * a + ptr->size + ptr->y, i * a + ptr->size + ptr->x, ptr, 0x00bcbcbc);  // GRIS
			j++;
		}
		i++;
	}
}

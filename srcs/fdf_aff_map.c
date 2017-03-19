/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aff_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:37:40 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:20:02 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_code(int y, int x, t_ptr *ptr)
{
	static int a = 0;
	static int x0 = 0;
	static int y0 = 0;

	if (a++ == 0)
	{
		x0 = x;
		y0 = y;
	}
	else
	{
		mlx_clr_img(ptr);
		if ((x - x0) > 0 && (x - x0) < 100)
			ptr->t1 += PI / 200;
		else if ((x - x0) < 0 && (x - x0) > -100)
			ptr->t1 -= PI / 200;
		if ((y - y0) > 0 && (y - y0) < 100)
			ptr->t2 -= PI / 200;
		else if ((y - y0) < 0 && (y - y0) > -100)
			ptr->t2 += PI / 200;
		x0 = x;
		y0 = y;
		fdf_key_code1(0, ptr);
	}
	return (0);
}

void	fdf_initialis(t_ptr *ptr)
{
	ptr->size_x = SIZE_X;
	ptr->size_y = SIZE_Y;
	ptr->sz = 1;
	ptr->d = 0;
	ptr->x = 0;
	ptr->y = 0;
	ptr->t1 = 0;
	ptr->t2 = 0;
	ptr->t3 = 0;
	ptr->h = 0;
	ptr->form = 0;
	ptr->rot = 36;
	ptr->v = 0;
	ptr->v1 = 0;
	ptr->c = 0;
}

void	fdf_aff_map(t_map *m, char *name)
{
	t_ptr	ptr;
	t_img	img;
	char	*str;

	str = ft_strjoin("Fdf - ", name);
	fdf_initialis(&ptr);
	ptr.map = m;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.size_x, ptr.size_y, str);
	img.ptr_img = mlx_new_image(ptr.mlx, SIZE_X, SIZE_Y);
	img.bts = mlx_get_data_addr(img.ptr_img, &(img.bpp),
		&(img.size_line), &(img.end));
	ptr.img = &img;
	fdf_map_in_windows(&ptr);
	mlx_hook(ptr.win, 2, 3, fdf_key_code1, &ptr);
	mlx_hook(ptr.win, 17, (1L << 17), fdf_close, &ptr);
	mlx_hook(ptr.win, 6, 1L << 6, mouse_code, &ptr);
	mlx_loop(ptr.mlx);
}

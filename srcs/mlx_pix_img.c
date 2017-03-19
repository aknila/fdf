/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pix_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:57 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:22:07 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_pix_img(t_ptr *ptr, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x) + 2] = r;
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x) + 1] = g;
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x)] = b;
	}
}

void	mlx_clr_img(t_ptr *ptr)
{
	int x;
	int y;

	x = 0;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			mlx_pix_img(ptr, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

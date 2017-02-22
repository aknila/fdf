/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aff_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:39:19 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:25:04 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mlx_aff_point(int x, int y, t_ptr *ptr, int color)
{
	int a;
	int b;
	int size;

	size = ptr->sz;
	a = x - size;
	while (a <= x + size)
	{
		b = y - size;
		while (b <= y + size)
		{
			// mlx_pixel_put(ptr->mlx, ptr->win, a, b, color);
			mlx_pix_img(ptr, a, b, color);
			b++;
		}
		a++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:39:07 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:28:58 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_conv_x(int x, int y, int z, t_ptr *ptr)
{
	int		h;
	int		a;
	int		xa;
	int		bx;
	double	dest;

	a = (2 * ptr->sz + 1);
	h = ptr->h;
	xa = ptr->map->c / 2;
	bx = ptr->sz + ptr->y;
	dest = y * cos(ptr->t2) * cos(ptr->t3);
	dest = dest + x * -sin(ptr->t3) * cos(ptr->t2);
	dest = (dest + (h * z) * sin(ptr->t2) + xa) * a + bx;
	return ((int)dest);
}

int		fdf_conv_y(int x, int y, int z, t_ptr *ptr)
{
	int		h;
	int		ya;
	int		by;
	double	dest;

	h = ptr->h;
	ya = ptr->map->l / 2;
	by = ptr->sz + ptr->x;
	dest = (y * (cos(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + sin(ptr->t3)
		* cos(ptr->t1)) + x * (-sin(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2)
		+ cos(ptr->t3) * cos(ptr->t1)) + (h * z) * -sin(ptr->t1)
		* cos(ptr->t2) + ya) * (2 * ptr->sz + 1) + by;
	return ((int)dest);
}

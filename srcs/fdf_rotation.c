/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:39:07 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:39:08 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int fdf_conv_x(int x, int y, int z, t_ptr *ptr)
{
	int h;
	int a;
	int xa;
	int bx;
	int dest;

	a = (2 * ptr->sz + 1);
	h = ptr->h;
	xa = 0;
	bx = ptr->sz + ptr->y;
	// dest = (y * cos(ptr->t2) * cos(ptr->t3) + x * -sin(ptr->t3) * cos(ptr->t2) + (h * z) * sin(ptr->t2) + xa) * a + bx;
	dest = y * cos(ptr->t2) * cos(ptr->t3);
	dest = dest + x * -sin(ptr->t3) * cos(ptr->t2);
	dest = (dest + (h * z) * sin(ptr->t2) + xa) * a + bx;
	// dest = y * cos(ptr->t2) * cos(ptr->t3);
	// dest = dest + x * -sin(ptr->t3) * cos(ptr->t2);
	// dest = (dest + (h * z) * sin(ptr->t2) + xa) * a + bx;
	return (dest);
}

int fdf_conv_y(int x, int y, int z, t_ptr *ptr)
{
	int h;
	int a;
	int ya;
	int by;
	int dest;

	// a = (2 * ptr->sz + 1);
	h = ptr->h;
	ya = 0;
	by = ptr->sz + ptr->x;
	// dest = (y * (cos(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + sin(ptr->t3) * cos(ptr->t1)) + x * ( -sin(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2) + cos(ptr->t3) * cos(ptr->t1)) + (h * z) * -sin(ptr->t1) * cos(ptr->t2) + ya) * a + by;
	a = -sin(ptr->t1) * -sin(ptr->t2);
	dest = y * (cos(ptr->t3) * a + sin(ptr->t3) * cos(ptr->t1));
	dest = dest + x * ( -sin(ptr->t3) * a + cos(ptr->t3) * cos(ptr->t1));
	a = (2 * ptr->sz + 1);
	dest = (dest + (h * z) * -sin(ptr->t1) * cos(ptr->t2) + ya) * a + by;
	// h = -sin(ptr->t3) * -sin(ptr->t1) * -sin(ptr->t2);
	// h = h + cos(ptr->t3) * cos(ptr->t1);
	// dest = dest + (x * h);
	// h = ptr->h;
	// dest = (dest + (h * z) * -sin(ptr->t1) * cos(ptr->t2) + ya) * a + by;
	return (dest);
}

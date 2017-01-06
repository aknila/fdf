/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:10:18 by aancel            #+#    #+#             */
/*   Updated: 2016/12/06 12:10:29 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void mlx_put_line(t_ptr *ptr)
{
	t_line l;

	l.dx = ABS(ptr->x1 - ptr->x0);
	l.sx = (ptr->x0 < ptr->x1 ? 1 : -1);
	l.dy = ABS(ptr->y1 - ptr->y0);
	l.sy = (ptr->y0 < ptr->y1 ? 1 : -1); 
 	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;

	while (1)
 	{
        mlx_pixel_put(ptr->mlx, ptr->win, ptr->x0, ptr->y0, ptr->colors);
    	if (ptr->x0 == ptr->x1 && ptr->y0 == ptr->y1)
    		break;
    	l.e2 = l.err;
    	if (l.e2 > -l.dx)
    	{
    		l.err -= l.dy;
    		ptr->x0 += l.sx;
    	}
    	if (l.e2 < l.dy)
    	{
    		l.err += l.dx;
    		ptr->y0 += l.sy;
		}
 	}
}

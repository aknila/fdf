/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:32 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:34 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_key_code4(int keycode, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == 126)
		ptr->x = ptr->x - (2 * ptr->sz + 1);
	if (keycode == 125)
		ptr->x = ptr->x + (2 * ptr->sz + 1);
	if (keycode == 124)
		ptr->y = ptr->y + (2 * ptr->sz + 1);
	if (keycode == 123)
		ptr->y = ptr->y - (2 * ptr->sz + 1);
	// if (ptr->x < 0 + ptr->sz)
	// 	ptr->x = 0;
	// if (ptr->x > ptr->size_x - ptr->sz)
	// 	ptr->x = ptr->size_x;
	// if (ptr->y < 0 + ptr->sz)
	// 	ptr->y = 0;
	// if (ptr->y > ptr->size_y - ptr->sz)
	// 	ptr->y = ptr->size_y;
	return (0);
}

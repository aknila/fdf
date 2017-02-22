/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:37 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:38 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_key_code5(int keycode, t_ptr *ptr)
{
	// mlx_clear_window(ptr->mlx, ptr->win);
	mlx_clr_img(ptr);
	if (keycode == 69)
	{
		ptr->sz += 1;
		if (ptr->sz > ptr->size_x / 6)
			ptr->sz -= 1;
		// ptr->x = (SIZE_Y / 2) - (ptr->map->l * (2 * ptr->sz + 1) / 2);
		// ptr->y = (SIZE_X / 2) - (ptr->map->c * (2 * ptr->sz + 1) / 2);
	}
	if (keycode == 78)
	{
		ptr->sz -= 1;
		if (ptr->sz < 0)
			ptr->sz = 0;
		// ptr->x = (SIZE_Y / 2) - (ptr->map->l * (2 * ptr->sz + 1) / 2);
		// ptr->y = (SIZE_X / 2) - (ptr->map->c * (2 * ptr->sz + 1) / 2);
	}
	if (keycode == 12)
	{
		ptr->c++;
		if (ptr->c > 10)
			ptr->c = 0;
	}
	if (keycode == 9)
	{
		ptr->v1++;
		if (ptr->v1 > 1)
			ptr->v1 = 0;
	}
	if (keycode == 8 && ptr->v1 == 1)
		ptr->v--;
	if (keycode == 11 && ptr->v1 == 1)
		ptr->v++;
	return (0);
}

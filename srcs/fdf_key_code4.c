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
	mlx_clr_img(ptr);
	if (keycode == 126)
		ptr->x = ptr->x - (2 * ptr->sz + (ptr->map->c / 5));
	if (keycode == 125)
		ptr->x = ptr->x + (2 * ptr->sz + (ptr->map->c / 5));
	if (keycode == 124)
		ptr->y = ptr->y + (2 * ptr->sz + (ptr->map->c / 5));
	if (keycode == 123)
		ptr->y = ptr->y - (2 * ptr->sz + (ptr->map->c / 5));
	if (keycode == 35)
	{
		ptr->x = (SIZE_Y / 2) - (ptr->map->l * (2 * ptr->sz + 1) / 2);
		ptr->y = (SIZE_X / 2) - (ptr->map->c * (2 * ptr->sz + 1) / 2);
	}
	return (0);
}

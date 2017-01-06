/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code2_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:05 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:07 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_key_code2_2(int keycode, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == 84)
		ptr->t2 += PI / 36;
	if (keycode == 87)
		ptr->t2 = 0;
	if (keycode == 91)
		ptr->t2 -= PI / 36;
	return (0);
}

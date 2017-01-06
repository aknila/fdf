/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code2_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:37:59 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:02 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_key_code2_1(int keycode, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == 83)
		ptr->t1 += PI / 36;
	if (keycode == 86)
		ptr->t1 = 0;
	if (keycode == 89)
		ptr->t1 -= PI / 36;
	return (0);
}

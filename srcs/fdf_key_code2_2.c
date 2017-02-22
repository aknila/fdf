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
	// mlx_clear_window(ptr->mlx, ptr->win);
	mlx_clr_img(ptr);
	if (keycode == 84 && ptr->form == 0)
		ptr->t2 += PI / ptr->rot;
	if (keycode == 87 && ptr->form == 0)
		ptr->t2 = 0;
	if (keycode == 91 && ptr->form == 0)
		ptr->t2 -= PI / ptr->rot;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code2_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:19 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:22 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_key_code2_3(int keycode, t_ptr *ptr)
{
	// mlx_clear_window(ptr->mlx, ptr->win);
	mlx_clr_img(ptr);
	if (keycode == 85 && ptr->form == 0)
		ptr->t3 += PI / ptr->rot;
	if (keycode == 88 && ptr->form == 0)
		ptr->t3 = 0;
	if (keycode == 92 && ptr->form == 0)
		ptr->t3 -= PI / ptr->rot;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:26 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:29 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_key_code3(int keycode, t_ptr *ptr)
{
	// mlx_clear_window(ptr->mlx, ptr->win);
	mlx_clr_img(ptr);
	if (keycode == 82 && ptr->form == 0)
		ptr->h--;
	if (keycode == 65 && ptr->form == 0)
		ptr->h++;
	if (keycode == 75)
	{
		ptr->d++;
		if (ptr->d > 1)
			ptr->d = 0;
	}
	return (0);
}

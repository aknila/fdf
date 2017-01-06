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
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == 69)
	{
		ptr->sz += 1;
		if (ptr->sz > ptr->size_x / 6)
			ptr->sz -= 1;
	}
	if (keycode == 78)
	{
		ptr->sz -= 1;
		if (ptr->sz < 0)
			ptr->sz = 0;
	}
	return (0);
}

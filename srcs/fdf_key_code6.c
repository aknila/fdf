/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_code6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:40 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:42 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_close(t_ptr *ptr)
{
	int i;

	i = 0;
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_image(ptr->mlx, ptr->img->ptr_img);
	free(ptr->map->map);
	free(ptr->map);
	exit(0);
	return (0);
}

int		fdf_key_code6(int keycode, t_ptr *ptr)
{
	mlx_clr_img(ptr);
	if (keycode == 53)
		fdf_close(ptr);
	if (keycode == 36)
	{
		ptr->form++;
		if (ptr->form > 1)
			ptr->form = 0;
	}
	return (0);
}

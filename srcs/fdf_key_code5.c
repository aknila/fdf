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
	mlx_clr_img(ptr);
	if (keycode == 69)
		ptr->sz = (ptr->sz + 1) > (ptr->size_x / 6) ?
			(ptr->sz - 1) : (ptr->sz + 1);
	if (keycode == 78)
		ptr->sz = (ptr->sz - 1) < 0 ? 0 : (ptr->sz - 1);
	if (keycode == 12)
		ptr->c = (ptr->c + 1) > 10 ? 0 : (ptr->c + 1);
	if (keycode == 9)
		ptr->v1 = ptr->v1 == 1 ? 0 : 1;
	if (keycode == 8 && ptr->v1 == 1)
		ptr->v--;
	if (keycode == 11 && ptr->v1 == 1)
		ptr->v++;
	return (0);
}

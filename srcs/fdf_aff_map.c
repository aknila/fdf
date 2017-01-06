/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aff_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:37:40 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:37:44 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_aff_map(int l, int c, int **tab)
{
	t_map m;
	t_ptr ptr;

	m.l = l;
	m.c = c;
	m.map = tab;
	ptr.map = &m;
	ptr.size_x = 1000;
	ptr.size_y = 1000;
	ptr.sz = 1;
	ptr.x = c / 2;
	ptr.y = l / 2;
	ptr.t1 = 0;
	ptr.t2 = 0;
	ptr.t3 = 0;
	ptr.h = 0;
	ptr.form = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.size_x, ptr.size_y, "Affichage");
	fdf_map_in_windows(&ptr);
	mlx_hook(ptr.win, 2, 3, fdf_key_code1, &ptr);
	mlx_loop(ptr.mlx);
}

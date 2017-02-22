/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_in_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:57 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:22:07 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_map_in_windows(t_ptr *ptr)
{
	int		i;
	int		j;
	int		i2;
	int		j2;
	t_map	*m;

	m = ptr->map;
	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			i2 = fdf_conv_x(i - (ptr->map->l / 2), j - (ptr->map->c / 2), m->map[i][j], ptr);
			j2 = fdf_conv_y(i - (ptr->map->l / 2), j - (ptr->map->c / 2), m->map[i][j], ptr);
			// mlx_pixel_put(ptr->mlx, ptr->win, i2, j2, 0x00bcbcbc);
			if (ptr->v1 == 0)
				mlx_pix_img(ptr, i2, j2, fdf_colo(m->map[i][j], ptr));
			if (j + 1 < m->c)
				fdf_aff_horizontale(i, j, m, ptr);
			if (i + 1 < m->l)
				fdf_aff_verticale(i, j, m, ptr);
			if (ptr->d == 1)
			{
				if (i + 1 < m->l && j + 1 < m->c)
					fdf_aff_diag_1(i, j, m, ptr);
				if (i > 0 && j + 1 < m->c)
					fdf_aff_diag_2(i, j, m, ptr);
			}
			j++;
		}
		i++;
	}
	// mlx_aff_point(SIZE_X / 2, SIZE_Y / 2, ptr, fdf_colo(11, ptr));
	mlx_put_info(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->ptr_img, 0, 0);
}

char	*fdf_putdec(int i, char *str)
{
	int a;
	int b;
	int c;

	a = i / 100;
	b = i % 100;
	c = b % 10;
	b = b / 10;
	a = ABS(a);
	b = ABS(b);
	c = ABS(c);
	if (i < 0)
	{
		return(ft_strjoin(str, ft_strjoin(" [ ", ft_strjoin("-", ft_strjoin(ft_itoa(a), ft_strjoin(",", ft_strjoin(ft_itoa(b), ft_strjoin(ft_itoa(c), " ]"))))))));
	}
	else
	{
		return(ft_strjoin(str, ft_strjoin(" [ ", ft_strjoin(ft_itoa(a), ft_strjoin(",", ft_strjoin(ft_itoa(b), ft_strjoin(ft_itoa(c), " ]")))))));
	}
	return (NULL);
}

void	mlx_put_info(t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->wth->win);
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 0, fdf_col(7), fdf_putdec((-180 / PI * ptr->t1), "Angle Axe X"));
	mlx_string_put(ptr->mlx, ptr->wth->win, 300, 0, fdf_col(3), "+ : {7}  0 : {4}  - : {1}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 25, fdf_col(7), fdf_putdec((-180 / PI * ptr->t2), "Angle Axe Y"));
	mlx_string_put(ptr->mlx, ptr->wth->win, 300, 25, fdf_col(3), "+ : {8}  0 : {5}  - : {2}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 50, fdf_col(7), fdf_putdec((180 / PI * ptr->t3), "Angle Axe Z"));
	mlx_string_put(ptr->mlx, ptr->wth->win, 300, 50, fdf_col(3), "+ : {9}  0 : {6}  - : {3}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 0, 75, fdf_col(8), "-------------------------------------------------------");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 100, fdf_col(6), ft_strjoin("Zoom: [ ", ft_strjoin(ft_itoa(ptr->sz), " ]")));
	mlx_string_put(ptr->mlx, ptr->wth->win, 375, 100, fdf_col(3), "+ : {+}  - : {-}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 125, fdf_col(6), ft_strjoin("Relief: [ x", ft_strjoin(ft_itoa(-1 * ptr->h), " ]")));
	mlx_string_put(ptr->mlx, ptr->wth->win, 375, 125, fdf_col(3), "+ : {0}  - : {.}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 0, 150, fdf_col(8), "-------------------------------------------------------");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 175, fdf_col(9), ft_strjoin("Deplacement X: [ ", ft_strjoin(ft_itoa(ptr->y + (ptr->map->c * (2 * ptr->sz + 1) / 2)), " ]")));
	mlx_string_put(ptr->mlx, ptr->wth->win, 285, 175, fdf_col(3), "< : {GAUCHE}  > : {DROITE}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 285, 175, fdf_col(3), "-             -");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 200, fdf_col(9), ft_strjoin("Deplacement Y: [ ", ft_strjoin(ft_itoa(ptr->x + (ptr->map->l * (2 * ptr->sz + 1) / 2)), " ]")));
	mlx_string_put(ptr->mlx, ptr->wth->win, 285, 200, fdf_col(3), "v : {HAUT}    ^ : {BAS}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 285, 200, fdf_col(3), "!             |");
	mlx_string_put(ptr->mlx, ptr->wth->win, 0, 225, fdf_col(8), "-------------------------------------------------------");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 250, fdf_col(2), ft_strjoin("Taille Fenetre: [ ", ft_strjoin(ft_itoa(SIZE_X), ft_strjoin("x", ft_strjoin(ft_itoa(SIZE_Y), " ]")))));
	mlx_string_put(ptr->mlx, ptr->wth->win, 325, 250, fdf_col(2), ft_strjoin("Image: [ ", ft_strjoin(ft_itoa(ptr->map->c), ft_strjoin("x", ft_strjoin(ft_itoa(ptr->map->l), " ]")))));
	mlx_string_put(ptr->mlx, ptr->wth->win, 0, 275, fdf_col(8), "-------------------------------------------------------");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 300, fdf_col(0), ft_strjoin("Couleur: [ ", ft_strjoin(ft_itoa(ptr->c), " ]")));
	mlx_string_put(ptr->mlx, ptr->wth->win, 350, 300, fdf_col(1), "(0 -> 10)   + : {Q}");
	if (ptr->c == 0)
	{
		mlx_string_put(ptr->mlx, ptr->wth->win, 200, 300, fdf_col(0), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 210, 300, fdf_col(1), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 220, 300, fdf_col(2), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 230, 300, fdf_col(3), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 240, 300, fdf_col(4), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 250, 300, fdf_col(5), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 260, 300, fdf_col(6), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 270, 300, fdf_col(7), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 280, 300, fdf_col(8), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 290, 300, fdf_col(9), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 300, 300, fdf_col(10), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 200, 300, fdf_col(0), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 210, 300, fdf_col(1), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 220, 300, fdf_col(2), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 230, 300, fdf_col(3), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 240, 300, fdf_col(4), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 250, 300, fdf_col(5), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 260, 300, fdf_col(6), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 270, 300, fdf_col(7), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 280, 300, fdf_col(8), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 290, 300, fdf_col(9), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 300, 300, fdf_col(10), "8");
	}
	else
	{
		mlx_string_put(ptr->mlx, ptr->wth->win, 200, 300, fdf_col(ptr->c) - 100, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 210, 300, fdf_col(ptr->c) - 80, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 220, 300, fdf_col(ptr->c) - 60, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 230, 300, fdf_col(ptr->c) - 40, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 240, 300, fdf_col(ptr->c) - 20, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 250, 300, fdf_col(ptr->c), "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 260, 300, fdf_col(ptr->c) + 20, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 270, 300, fdf_col(ptr->c) + 40, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 280, 300, fdf_col(ptr->c) + 60, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 290, 300, fdf_col(ptr->c) + 80, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 300, 300, fdf_col(ptr->c) + 100, "0");
		mlx_string_put(ptr->mlx, ptr->wth->win, 200, 300, fdf_col(ptr->c) - 100, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 210, 300, fdf_col(ptr->c) - 80, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 220, 300, fdf_col(ptr->c) - 60, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 230, 300, fdf_col(ptr->c) - 40, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 240, 300, fdf_col(ptr->c) - 20, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 250, 300, fdf_col(ptr->c), "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 260, 300, fdf_col(ptr->c) + 20, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 270, 300, fdf_col(ptr->c) + 40, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 280, 300, fdf_col(ptr->c) + 60, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 290, 300, fdf_col(ptr->c) + 80, "8");
		mlx_string_put(ptr->mlx, ptr->wth->win, 300, 300, fdf_col(ptr->c) + 100, "8");
	}
	mlx_string_put(ptr->mlx, ptr->wth->win, 0, 325, fdf_col(8), "-------------------------------------------------------");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 350, fdf_col(5), "Mode: Minimap {ENTREE} (       Aff. Diagonale {/} (");
	if (ptr->d == 1)
		mlx_string_put(ptr->mlx, ptr->wth->win, 512, 350, fdf_col(5), "ON)");
	else
		mlx_string_put(ptr->mlx, ptr->wth->win, 512, 350, fdf_col(5), "OFF)");
	if (ptr->form == 1)
		mlx_string_put(ptr->mlx, ptr->wth->win, 242, 350, fdf_col(5), "ON)");
	else
		mlx_string_put(ptr->mlx, ptr->wth->win, 242, 350, fdf_col(5), "OFF)");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 375, fdf_col(5), "Void {V} [                             - : {C}  + : {B}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 112, 375, fdf_col(5), ft_strjoin(ft_itoa(ptr->v), " ]"));
	if (ptr->v1 == 1)
		mlx_string_put(ptr->mlx, ptr->wth->win, 182, 375, fdf_col(5), "(ON)");
	else
		mlx_string_put(ptr->mlx, ptr->wth->win, 182, 375, fdf_col(5), "(OFF)");
	mlx_string_put(ptr->mlx, ptr->wth->win, 2, 400, fdf_col(5), "Exit: {ECHAP}");
	mlx_string_put(ptr->mlx, ptr->wth->win, 0, 425, fdf_col(8), "-------------------------------------------------------");
}
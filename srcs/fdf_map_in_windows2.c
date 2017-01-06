#include "../includes/fdf.h"

void	fdf_map_in_windows2(t_ptr *ptr)
{
	int i;
	int j;
	int a;
	t_map *m;

	m = ptr->map;
	a = (2 * ptr->sz + 1);
	i = 0;
	while (i < m->l)
	{
		j = 0;
		while (j < m->c)
		{
			if (m->map[i][j] % 4 == 0)
				mlx_aff_point(j * a + ptr->sz + ptr->y, i * a + ptr->sz + ptr->x, ptr, 0x00000000);  // NOIR
			if (m->map[i][j] % 4 == 1)
				mlx_aff_point(j * a + ptr->sz + ptr->y, i * a + ptr->sz + ptr->x, ptr, 0x00ffaf00);  // JAUNE
			if (m->map[i][j] % 4 == 2)
				mlx_aff_point(j * a + ptr->sz + ptr->y, i * a + ptr->sz + ptr->x, ptr, 0x00FFFFFF);  // BLANC
			if (m->map[i][j] % 4 == 3)
				mlx_aff_point(j * a + ptr->sz + ptr->y, i * a + ptr->sz + ptr->x, ptr, 0x00bcbcbc);  // GRIS
			j++;
		}
		i++;
	}
}

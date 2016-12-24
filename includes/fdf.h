/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2016/12/05 02:49:49 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "color.h"
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define SIZE_X 1000
# define SIZE_Y 1000
# define PI 3.141592653589793

typedef struct	s_line
{
	int 		dx;
	int 		dy;
	int 		err;
	int 		sx;
	int 		sy;
	int			e2;
}				t_line;

typedef struct  s_map
{
	int l;
	int c;
	int **map;
}				t_map;

typedef struct	s_ptr
{
	int			x;
	int			y;
	int			b;
	int			form;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	double		t1;
	double		t2;
	double		t3;
	int			size_x;
	int			size_y;
	int			size;
	int			colors;
	void 		*mlx;
	void		*win;
	t_map		*map;
}				t_ptr;

int		**fdf_put_in_map(int **map, char *str);
int		**fdf_make_map(int n, int s, char *str);
int		**fdf_take_dimension(char *str, int *a, int *b);
int		**fdf_map_extract(int fd, int *a, int *b);
void	fdf_aff_map(int a, int b, int **map);
void	fdf_map_in_windows(t_ptr *ptr);
void	fdf_map_in_windows2(t_ptr *ptr);
int 	aff_point(int x, int y, t_ptr *ptr, int color);
int		key_code(int keycode, t_ptr *ptr);
void	mlx_put_line(t_ptr *ptr);

#endif

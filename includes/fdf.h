/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/01/07 17:36:35 by aancel           ###   ########.fr       */
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
# define SIZE_X 1500
# define SIZE_Y 1000
# define SH2_X 550
# define SH2_Y 450
# define PI 3.141592653589793
# define BUUFF 100000

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		err;
	int		sx;
	int		sy;
	int		e2;
}				t_line;

typedef struct	s_map
{
	int			l;
	int			c;
	int			**map;
}				t_map;

typedef struct	s_img
{
	void		*ptr_img;
	char		*bts;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_ptr
{
	int			d;
	int			x;
	int			y;
	int			h;
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
	int			sz;
	int			rot;
	int			colors;
	int			v;
	int			v1;
	int			c;
	void		*mlx;
	void		*win;
	t_map		*map;
	t_img		*img;
}				t_ptr;

int				fdf_check_ext(char *str);
int				fdf_main(int argc, char **argv);
void			fdf_aff_map(t_map *m, char *name);
void			fdf_map_in_windows(t_ptr *ptr);
void			fdf_map_in_windows2(t_ptr *ptr);
int				mlx_aff_point(int x, int y, t_ptr *ptr, int color);
int				fdf_key_code1(int kc, t_ptr *ptr);
int				fdf_key_code2_1(int keycode, t_ptr *ptr);
int				fdf_key_code2_2(int keycode, t_ptr *ptr);
int				fdf_key_code2_3(int keycode, t_ptr *ptr);
int				fdf_key_code3(int keycode, t_ptr *ptr);
int				fdf_key_code4(int keycode, t_ptr *ptr);
int				fdf_key_code5(int keycode, t_ptr *ptr);
int				fdf_key_code6(int keycode, t_ptr *ptr);
void			mlx_put_line(t_ptr *ptr);
void			fdf_aff_horizontale(int i, int j, t_map *m, t_ptr *ptr);
void			fdf_aff_verticale(int i, int j, t_map *m, t_ptr *ptr);
int				fdf_conv_x(int x, int y, int z, t_ptr *ptr);
int				fdf_conv_y(int x, int y, int z, t_ptr *ptr);
int				fdf_col(int m);
int				ft_error(int error);
int				ft_count_s(char *str);
int				**fdf_put_in_map(int **map, int fd);
t_map			*fdf_map_extract(int fd, char *filename);
char			*fdf_extracting(int fd);
int				fdf_check_file(int *l, int *a, int fd);
int				ft_isfullnum(char *str);
int				fdf_close(t_ptr *ptr);
int				mouse_code(int x, int y, t_ptr *ptr);
void			mlx_pix_img(t_ptr *ptr, int x, int y, int color);
void			mlx_clr_img(t_ptr *ptr);
void			fdf_aff_diag_1(int i, int j, t_map *m, t_ptr *ptr);
void			fdf_aff_diag_2(int i, int j, t_map *m, t_ptr *ptr);
int				fdf_colo(int nbr, t_ptr *ptr);
void			fdf_initialis(t_ptr *ptr);
int				fdf_check_file2(char **str1, int *l, int *a);
void			fdf_aff_conv_point(t_ptr *ptr, t_map *m, int i, int j);

#endif

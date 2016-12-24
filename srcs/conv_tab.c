/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:35:47 by aancel            #+#    #+#             */
/*   Updated: 2016/12/20 19:27:08 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**fdf_put_in_map(int **map, char *str)
{
	int		n;
	int		s;
	int		i;

	n = 0;
	s = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			map[n][s++] = ft_atoi(&str[i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i++] == '\n')
		{
			n++;
			s = 0;
		}
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
			i++;
	}
	return (map);
}

int		**fdf_make_map(int n, int s, char *str)
{
	int		i;
	int		**map;

	if (!(map = (int **)malloc(sizeof(int *) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * s)))
			return (NULL);
		i++;
	}
	map = fdf_put_in_map(map, str);
	return (map);
}

int		**fdf_take_dimension(char *str, int *a, int *b)
{
	int		**map;
	int		i;
	int		n;
	int		s;

	i = 0;
	n = 1;
	s = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		if (str[i] == ' ' && str[i + 1] != ' ')
			s++;
		i++;
	}
	if (str[i - 1] == '\n')
		n -= 1;
	s /= n;
	s++;
	*a = n;
	*b = s;
	map = fdf_make_map(n, s, str);
	return (map);
}

int		**fdf_map_extract(int fd, int *a, int *b)
{
	char	buf[101];
	int		r;
	char	*str;
	int		**map;

	str = "";
	r = 100;
	while (r == 100)
	{
		r = read(fd, buf, 100);
		str = ft_strjoin(str, buf);
		ft_memset(buf, '\0', 100);
	}
	map = fdf_take_dimension(str, a, b);
	return (map);
}

int		main(int argc, char **argv)
{
	int		**map;
	int		fd;
	int		a;
	int		b;

	a = 0;
	b = 0;
	map = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		map = fdf_map_extract(fd, &a, &b);
	}
	fdf_aff_map(a, b, map);
	return (0);
}

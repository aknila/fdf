/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:38:53 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:38:54 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_count_s(char *str)
{
	int i;
	int s;

	i = 0;
	s = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\n')
			s++;
		i++;
	}
	s++;
	return (s);
}

int		ft_isfullnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
		{
			return (-1);
		}
		else if (str[i] == '-' && ft_isdigit(str[i + 1]) == 0)
		{
			return (-1);
		}
		else if (ft_isdigit(str[i]) == 0 && str[i] != ' '
			&& str[i] != '\0' && str[i] != '-')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int		fdf_check_file(int *l, int *a, int fd)
{
	int		i;
	char	**map;
	char	*str1;
	char	*tmp;
	char	*buf;

	*l = 0;
	*a = 0;
	// ft_strdel(str);
	tmp = NULL;
	map = NULL;
	if (!(str1 = (char *)malloc(sizeof(char) * 11)))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		return (-1);
	ft_memset(buf, '\0', 10001);
	ft_memset(str1, '\0', 11);
	while (read(fd, buf, 10000) > 0)
	{
		tmp = str1;
		if (!(str1 = ft_strjoin(str1, buf)))
		{
			// ft_strdel(&str1);
			ft_strdel(&tmp);
			ft_strdel(&buf);
			return (-1);
		}
		ft_strdel(&tmp);
		ft_memset(buf, '\0', 10001);
	}
	map = ft_strsplit(str1, '\n');
	free(str1);
	i = 0;
	while (map[i])
	{
		if (*l == 0)
			*a = ft_count_s(map[i]);
		else
		{
			if (*a != ft_count_s(map[i]))
				return (-1);
		}
		if (ft_isfullnum(map[i]) == -1)
			return (-1);
		*l += 1;
		free(map[i]);
		i++;
	}
	// while (1) ;
	free(map);
	return (0);
}



// 	while (get_next_line(fd, str) != 0)
// 	{
// 		ft_putnbr(ft_strlen(*str));
// 		ft_putchar('\n');
// 		// *str = ft_strtrim(*str);
// 		if (*l == 0)
// 			*a = ft_count_s(*str);
// 		else
// 		{
// 			if (*a != (i = ft_count_s(*str)))
// 			{
// 				ft_putnbr(*a);
// 				ft_putchar('-');
// 				ft_putnbr(i);
// 				ft_putchar('-');
// 				ft_putnbr(*l);
// 				return (-1);
// 			}
// 		}
// 		if (ft_isfullnum(*str) == -1)
// 			return (-1);
// 		*l += 1;
// 		ft_strdel(str);
// 	}
// 	return (0);
// }

t_map	*fdf_map_extract(int fd, char *filename)
{
	int		l;
	int		a;
	// int		a1;
	t_map	*m;
	int		**map;

	m = NULL;
	map = NULL;
	if (fdf_check_file(&l, &a, fd) == -1)
		return (NULL);
	if (!(m = malloc(sizeof(t_map))))
		return (NULL);
	m->map = NULL;
	if (!(map = (int **)malloc(sizeof(int *) * l)))
		return (NULL);
	m->l = 0;
	while (m->l < l)
	{
		if (!(map[m->l++] = (int *)malloc(sizeof(int) * a)))
			return (NULL);
		// a1 = 0;
		// while (a > a1)
			// map[m->l - 1][a1++] = 0;
	}
	m->c = a;
	close(fd);
	fd = open(filename, O_RDONLY);
	if (!(m->map = fdf_put_in_map(map, fd)))
		return (NULL);
	return (m);
}

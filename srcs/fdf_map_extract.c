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

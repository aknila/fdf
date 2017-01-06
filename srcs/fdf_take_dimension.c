/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_take_dimension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:39:11 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:39:11 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

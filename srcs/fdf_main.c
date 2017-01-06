/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:37:15 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:37:32 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	int		**map;
	int		fd;
	int		a;
	int		b;

	a = 0;
	b = 0;
	map = NULL;
	if (argc != 2)
	{
		ft_putstr(C_ROUGE "\tusage : ./fdf {filename}\n");
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		map = fdf_map_extract(fd, &a, &b);
	}
	fdf_aff_map(a, b, map);
	return (0);
}

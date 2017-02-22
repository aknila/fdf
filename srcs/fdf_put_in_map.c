/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 02:39:03 by aancel            #+#    #+#             */
/*   Updated: 2017/01/05 02:39:04 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*fdf_extracting(int fd)
{
	char	*tmp;
	char	*str;
	char	*buf;

	tmp = NULL;
	if (!(str = (char *)malloc(sizeof(char) * 11)))
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		return (NULL);
	ft_memset(buf, '\0', 10001);
	ft_memset(str, '\0', 11);
	while (read(fd, buf, 10000) > 0)
	{
		tmp = str;
		if (!(str = ft_strjoin(str, buf)))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
		ft_strdel(&tmp);
		ft_memset(buf, '\0', 10000);
	}
	return (str);
}

int		**fdf_put_in_map(int **map, int fd)
{
	int		n;
	int		s;
	int		i;
	char	*str;

	n = 0;
	i = 0;
	s = 0;
	if (!(str = fdf_extracting(fd)))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			map[n][s++] = ft_atoi(&str[i]);
			while (str[i] && (str[i] == '-'
				|| (str[i] >= '0' && str[i] <= '9')))
				i++;
		}
		n += (str[i] && str[i] == '\n' ? 1 : 0);
		s = (str[i] && str[i++] == '\n' ? 0 : s);
		i += (str[i] && str[i] == ' ' ? 1 : 0);
	}
	free(str);
	return (map);
}

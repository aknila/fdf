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

int		ft_error(int error)
{
	if (error == 0)
		ft_putstr(C_ROUGE "\terror : invalid file\n" FIN);
	if (error == 1)
		ft_putstr(C_ROUGE "\terror : bad extension\n" FIN);
	return (-1);
}

int		fdf_check_ext(char *str)
{
	int		i;
	int		j;
	char	ext[5];

	i = ft_strlen(str);
	i -= 4;
	j = 0;
	while (j < 4)
	{
		ext[j] = str[i];
		j++;
		i++;
	}
	ext[4] = '\0';
	if (ft_strcmp(ext, ".fdf") != 0)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*m;
	int		fd;
	// char	*str;
	char	*buf;

	// str = NULL;
	if(!(buf = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	if (argc != 2)
	{
		ft_putstr(C_ROUGE "\tusage : ./fdf {filename}\n");
		return (-1);
	}
	else if (fdf_check_ext(argv[1]) == -1)
		return (ft_error(1));
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (read(fd, buf, 1) == -1)
		{
			free(buf);
			return (ft_error(0));
		}
		free(buf);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if (!(m = fdf_map_extract(fd, argv[1])))
			return (ft_error(0));
		fdf_aff_map(m, argv[1]);
	}
	return (0);
}

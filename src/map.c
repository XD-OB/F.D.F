/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ilyass.sh@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:21:38 by ishaimou          #+#    #+#             */
/*   Updated: 2018/12/20 00:13:26 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		map_count(char *argv, t_fdf *fdf)
{
	char	*line;
	char	**tab;
	int		fd;

	if ((fd = open(argv, O_RDONLY)) == -1)
		exit(-1);
	if (get_next_line(fd, &line) == -1)
		exit(-1);
	fdf->map.nline = 1;
	fdf->map.ncolumn = 0;
	tab = ft_strsplit(line, ' ');
	free(line);
	while (*tab)
	{
		fdf->map.ncolumn++;
		tab++;
	}
	while (get_next_line(fd, &line) > 0)
	{
		fdf->map.nline++;
		free(line);
	}
	close(fd);
}

static void		map_alloc(t_fdf *fdf)
{
	fdf->map.y = 0;
	fdf->map.map = (t_coloralt**)malloc(sizeof(t_coloralt*) * fdf->map.nline);
	while (fdf->map.y < fdf->map.nline)
	{
		fdf->map.map[fdf->map.y] = (t_coloralt*)malloc(sizeof(t_coloralt)
			* fdf->map.ncolumn);
		fdf->map.y++;
	}
}

static void		map_populate(int fd, t_fdf *fdf)
{
	char	*line;
	char	**tab;
	char	*str_hex;

	fdf->map.y = 0;
	while (get_next_line(fd, &line))
	{
		fdf->map.x = 0;
		tab = ft_strsplit(line, ' ');
		while (fdf->map.x < fdf->map.ncolumn)
		{
			fdf->map.map[fdf->map.y][fdf->map.x].color = fdf->color;
			if ((str_hex = ft_strchr(tab[fdf->map.x], 'x')) != NULL)
				ft_xtoi(++str_hex, fdf);
			str_hex = NULL;
			fdf->map.map[fdf->map.y][fdf->map.x].alt = ft_atoi(tab[fdf->map.x]);
			free(tab[fdf->map.x]);
			fdf->map.x++;
		}
		fdf->map.y++;
		free(tab);
		free(line);
	}
}

static void		map_check(t_fdf *fdf, int fd)
{
	char	*line;
	char	**tab;

	fdf->map.error = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		fdf->map.y = 0;
		while (tab[fdf->map.y])
			(fdf->map.y)++;
		if (fdf->map.y != fdf->map.ncolumn)
		{
			fdf->map.error = 1;
			return ;
		}
	}
}

void			map_create(char *av, t_fdf *fdf)
{
	int		fd;

	map_count(av, fdf);
	set_window(fdf);
	init_fdf(fdf);
	if ((fd = open(av, O_RDONLY)) == -1)
		exit(-1);
	map_check(fdf, fd);
	if (fdf->map.error == 1)
	{
		ft_putstr("Error Invalid File :(\n");
		exit(-1);
	}
	close(fd);
	map_alloc(fdf);
	fd = open(av, O_RDONLY);
	map_populate(fd, fdf);
	close(fd);
}

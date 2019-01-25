/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:28:38 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/20 01:22:05 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		menu(t_fdf *fdf)
{
	int		i;

	mlx_string_put(fdf->mlx, fdf->win, 30, 10, 0x6666ff, "CLOSE : ESC");
	mlx_string_put(fdf->mlx, fdf->win, 30, 30, 0x6666ff, "RESET : SPACE");
	mlx_string_put(fdf->mlx, fdf->win, 30, 50, 0x6666ff, "ZOOM  : 1  2");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0x6666ff, "ROTATION  :  C");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0x6666ff, "PROJECTION: P T");
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0x6666ff, "ALTITUDE  : -  +");
	mlx_string_put(fdf->mlx, fdf->win, 30, 130, 0x6666ff, "MOVE  : <-  ->");
	mlx_string_put(fdf->mlx, fdf->win, 30, 150, 0x6666ff, "      : UP  DOWN");
	traceline(fdf, point(0, 180), point(200, 180), 0xff6600);
	traceline(fdf, point(200, 180), point(200, 0), 0xff6600);
	i = 0;
	while (++i <= 24)
	{
		traceline(fdf, point(201, i), point(fdf->width, i), fdf->color);
		traceline(fdf, point(0, fdf->height - i),
				point(fdf->width, fdf->height - i), fdf->color);
	}
}

void			command_bloc(t_fdf *fdf)
{
	int		i;

	menu(fdf);
	mlx_string_put(fdf->mlx, fdf->win, fdf->width / 4, fdf->height - 23, 0,
			"obelouch   ------BY------   ishaimou");
	i = 0;
	while (++i <= 20)
	{
		traceline(fdf, point(fdf->width - 22, i + 2),
				point(fdf->width - 2, i + 2), 0xFF0000);
		traceline(fdf, point(fdf->width - 44, i + 2),
				point(fdf->width - 24, i + 2), 0xFFCC00);
		traceline(fdf, point(fdf->width - 66, i + 2),
				point(fdf->width - 46, i + 2), 0x00CCFF);
		traceline(fdf, point(fdf->width - 88, i + 2),
				point(fdf->width - 68, i + 2), 0x40FF00);
		traceline(fdf, point(fdf->width - 110, i + 2),
				point(fdf->width - 90, i + 2), 0xFF66CC);
		traceline(fdf, point(fdf->width - 132, i + 2),
				point(fdf->width - 112, i + 2), 0xCC66FF);
		traceline(fdf, point(fdf->width - 154, i + 2),
				point(fdf->width - 134, i + 2), 0x00FFCC);
		traceline(fdf, point(fdf->width - 176, i + 2),
				point(fdf->width - 156, i + 2), 0x669999);
	}
}

void			set_window(t_fdf *fdf)
{
	fdf->width = (35 * fdf->map.ncolumn) + 400;
	fdf->height = (35 * fdf->map.nline) + 300;
	if (fdf->width > 2400)
		fdf->width = 2400;
	if (fdf->height > 1200)
		fdf->height = 1200;
}

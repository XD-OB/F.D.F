/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceformparal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:57:49 by obelouch          #+#    #+#             */
/*   Updated: 2018/12/19 23:19:03 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		color_linep(t_fdf *fdf, int *flag)
{
	if (fdf->map.map[fdf->map.y][fdf->map.x].color != 0xFFFFFF && *flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->map.map[fdf->map.y]
				[fdf->map.x].color);
	else if (*flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->color);
	fdf->p1 = fdf->p2;
	*flag = 1;
}

static void		put_lines_paral(t_fdf *fdf)
{
	t_point		pi;
	int			flag;

	pi = fdf->p0;
	fdf->map.y = -1;
	while (++fdf->map.y < fdf->map.nline)
	{
		flag = 0;
		fdf->map.x = -1;
		fdf->p1 = pi;
		while (++fdf->map.x < fdf->map.ncolumn)
		{
			fdf->p2 = point(pi.x + ((fdf->map.x) * fdf->step), pi.y);
			fdf->p2.x -= (fdf->map.map[fdf->map.y]
					[fdf->map.x].alt * fdf->depth);
			fdf->p2.y -= (fdf->map.map[fdf->map.y]
					[fdf->map.x].alt * fdf->depth) * tan(M_PI / 3);
			color_linep(fdf, &flag);
		}
		pi.y += fdf->step;
	}
}

static void		color_columnp(t_fdf *fdf, int *flag)
{
	if (fdf->map.map[fdf->map.y][fdf->map.x].color != 0xFFFFFF && *flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->map.map
				[fdf->map.y][fdf->map.x].color);
	else if (*flag == 1)
		traceline(fdf, fdf->p1, fdf->p2, fdf->color);
	fdf->p1 = fdf->p2;
	*flag = 1;
}

static void		put_columns_paral(t_fdf *fdf)
{
	t_point		pi;
	int			flag;

	pi = fdf->p0;
	fdf->map.x = -1;
	while (++fdf->map.x < fdf->map.ncolumn)
	{
		flag = 0;
		fdf->map.y = -1;
		fdf->p1 = pi;
		while (++fdf->map.y < fdf->map.nline)
		{
			fdf->p2 = point(pi.x, pi.y + (fdf->map.y * fdf->step));
			fdf->p2.x -= (fdf->map.map[fdf->map.y]
					[fdf->map.x].alt * fdf->depth);
			fdf->p2.y -= (fdf->map.map[fdf->map.y]
					[fdf->map.x].alt * fdf->depth) * tan(M_PI / 3);
			color_columnp(fdf, &flag);
		}
		pi.x += fdf->step;
	}
}

void			put_fdf_paral(t_fdf *fdf)
{
	put_lines_paral(fdf);
	put_columns_paral(fdf);
	command_bloc(fdf);
}
